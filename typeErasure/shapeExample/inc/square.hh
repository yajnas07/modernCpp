
#pragma once

class Square {
  public:
    int prop{};

    explicit Square(double side) : side_(side) {}

    [[nodiscard]] double get_side() const noexcept { return side_; }

     void draw()const  {
        std::cout << "Drawing a square of side:" << side_ << std::endl;
    }

  private:
    double side_;
};
