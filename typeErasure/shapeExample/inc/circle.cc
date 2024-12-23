
#pragma once

class Circle {
  public:
    int prop{};

    explicit Circle(double radius) : radius_(radius) {}

    [[nodiscard]] double get_radius() const noexcept { return radius_; }

    void draw() const {
        std::cout << "Drawing a circle of radius:" << radius_ << std::endl;
    }

  private:
    double radius_;
};