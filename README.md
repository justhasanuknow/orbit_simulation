# cpp-start

Solar system simülasyonu — CMake tabanlı C++ projesi.

## Gereksinimler

- CMake 3.10+
- C++ derleyici (g++, clang++, vb.)
- Bash

## Build & Çalıştırma

Projeyi derleyip çalıştırmak için kök dizindeki `build.sh` scripti kullanılır.

```bash
./build.sh                # konfigüre + build + çalıştır
./build.sh clean          # build/ dizinini silip sıfırdan başlar
./build.sh arg1 arg2      # argümanları main'e iletir
```

Script şunları yapar:

1. `cmake -S . -B build` ile projeyi konfigüre eder (cache varsa yeniden kullanır → hızlı incremental build).
2. `cmake --build build -j$(nproc)` ile paralel derler.
3. `build/main` executable'ını çalıştırır, verilen argümanları aktarır.

## Proje Yapısı

```
.
├── CMakeLists.txt
├── build.sh
└── src/
    ├── main.cpp
    └── core/
        ├── planet/
        ├── simulation/
        └── solar_system/
```

## Manuel Build

`build.sh` kullanmadan elle derlemek istersen:

```bash
cmake -S . -B build
cmake --build build -j$(nproc)
./build/main
```
