#include <iostream>
#include <string>

class Computer {
public:
    void setCPU(const std::string& cpu) {
        cpu_ = cpu;
    }

    void setRAM(const std::string& ram) {
        ram_ = ram;
    }

    void setStorage(const std::string& storage) {
        storage_ = storage;
    }

    void info() const {
        std::cout << "Computer with CPU: " << cpu_
            << ", RAM: " << ram_
            << ", Storage: " << storage_ << "\n";
    }

private:
    std::string cpu_;
    std::string ram_;
    std::string storage_;
};

class ComputerBuilder {
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual Computer getResult() const = 0;
};


class GamingComputerBuilder : public ComputerBuilder {
private:
    Computer computer;

public:
    void buildCPU() override {
        computer.setCPU("High-end Gaming CPU");
    }

    void buildRAM() override {
        computer.setRAM("32GB Gaming RAM");
    }

    void buildStorage() override {
        computer.setStorage("1TB SSD");
    }

    Computer getResult() const override {
        return computer;
    }
};


class OfficeComputerBuilder : public ComputerBuilder {
private:
    Computer computer;

public:
    void buildCPU() override {
        computer.setCPU("Standard Office CPU");
    }

    void buildRAM() override {
        computer.setRAM("8GB Office RAM");
    }

    void buildStorage() override {
        computer.setStorage("500GB HDD");
    }

    Computer getResult() const override {
        return computer;
    }
};


class ComputerDirector {
public:
    Computer construct(ComputerBuilder& builder) {
        builder.buildCPU();
        builder.buildRAM();
        builder.buildStorage();
        return builder.getResult();
    }
};

int main() {
   
    GamingComputerBuilder gamingBuilder;
    ComputerDirector director;
    Computer gamingComputer = director.construct(gamingBuilder);

    std::cout << "Gaming Computer:\n";
    gamingComputer.info();

   
    OfficeComputerBuilder officeBuilder;
    Computer officeComputer = director.construct(officeBuilder);

    std::cout << "\nOffice Computer:\n";
    officeComputer.info();

    return 0;
}