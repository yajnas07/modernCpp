#pragma once

class Rectangle {
  public:
    explicit Rectangle(double l, double b) : length_(l), bredth_(b) {}

    [[nodiscard]] double get_length() const noexcept { return length_; }
    [[nodiscard]] double get_bredth() const noexcept { return bredth_; }

     void draw() {
        std::cout << "Drawing a Rectangle of length:" << length_ << " and bredth:" << bredth_ << std::endl;
    }

  private:
    double length_;
    double bredth_;
};

