#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/build"

# Colors — only when stdout is a TTY
if [[ -t 1 ]]; then
    C_BOLD=$'\033[1m'; C_DIM=$'\033[2m'
    C_BLUE=$'\033[34m'; C_GREEN=$'\033[32m'
    C_YELLOW=$'\033[33m'; C_RED=$'\033[31m'
    C_RESET=$'\033[0m'
else
    C_BOLD=''; C_DIM=''; C_BLUE=''; C_GREEN=''; C_YELLOW=''; C_RED=''; C_RESET=''
fi

step() {
    echo
    echo "${C_BLUE}${C_BOLD}==>${C_RESET} ${C_BOLD}$1${C_RESET}"
}

# Runs a command in the background while displaying a spinner.
# Output is captured; on success only an OK line + elapsed time is shown,
# on failure the full log is printed.
with_spinner() {
    local msg=$1
    shift

    # Not a TTY — just run plainly, no spinner
    if [[ ! -t 1 ]]; then
        "$@"
        return $?
    fi

    local log
    log=$(mktemp)

    "$@" >"$log" 2>&1 &
    local pid=$!

    # On Ctrl+C kill the background process too
    trap 'kill '"$pid"' 2>/dev/null; rm -f '"$log"'; exit 130' INT TERM

    local frames='⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏'
    local i=0
    local start=$SECONDS

    # Hide cursor
    printf '\033[?25l'

    while kill -0 "$pid" 2>/dev/null; do
        local frame=${frames:$((i % ${#frames})):1}
        printf '\r%s%s%s %s %s(%ds)%s ' \
            "$C_YELLOW" "$frame" "$C_RESET" \
            "$msg" \
            "$C_DIM" $((SECONDS - start)) "$C_RESET"
        sleep 0.1
        i=$((i + 1))
    done

    wait "$pid"
    local exit_code=$?

    # Restore cursor, clear line
    printf '\033[?25h\r\033[K'
    trap - INT TERM

    local elapsed=$((SECONDS - start))
    if [[ $exit_code -eq 0 ]]; then
        printf '%s✓%s %s %s(%ds)%s\n' \
            "$C_GREEN" "$C_RESET" "$msg" "$C_DIM" "$elapsed" "$C_RESET"
    else
        printf '%s✗%s %s %s(exit %d, %ds)%s\n' \
            "$C_RED" "$C_RESET" "$msg" "$C_DIM" "$exit_code" "$elapsed" "$C_RESET"
        echo
        cat "$log"
    fi

    rm -f "$log"
    return $exit_code
}

# --- Flow ---

if [[ "${1:-}" == "clean" ]]; then
    step "Clean"
    rm -rf "$BUILD_DIR"
    echo "build/ removed"
    shift
fi

step "Configure (CMake)"
if [[ ! -d "$BUILD_DIR" ]]; then
    echo "${C_DIM}First build — raylib will be downloaded, this may take a few minutes.${C_RESET}"
    with_spinner "Fetching dependencies + CMake configure" \
        cmake -S "$SCRIPT_DIR" -B "$BUILD_DIR"
else
    # Incremental — fast, let output stream directly
    cmake -S "$SCRIPT_DIR" -B "$BUILD_DIR"
fi

step "Build"
cmake --build "$BUILD_DIR" -j"$(nproc)"

step "Run"
"$BUILD_DIR/main" "$@"
