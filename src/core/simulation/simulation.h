#pragma once

class Simulation {
  private:
    Simulation() = default;
    ~Simulation() = default;

  public:
    static Simulation& getInstance() {
        static Simulation instance;
        return instance;
    }

    Simulation(const Simulation&) = delete;
    Simulation& operator=(const Simulation&) = delete;

    void initializeSimulation() const;
    void finalizeSimulation() const;
};