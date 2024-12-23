
#pragma once

// #include "circle.hh"
// #include "square.hh"

#include <memory>
#include <type_traits>
#include <utility>

class Shape {
    // Shape's interface is implemented as hidden friends.
    friend void draw(Shape const& shape) {
        // Dispatch in ShapeModel<ConcreteShape>::draw().
        shape.pimpl_->do_draw();
    }

private:
    class ShapeConcept {
    public:
        virtual ~ShapeConcept(){};

        // Shape's interface declaration. The real functions containing implementations are named
        // without the do_ prefix, but in order to facilitate ADL in finding the free functions
        // implementing the interface, the virtual interface functions must be named differently.
        virtual void do_draw() const = 0;


        // Make ShapeConcept's children copyable through ShapeConcept pointer.
        [[nodiscard]] virtual std::unique_ptr<ShapeConcept> clone() const = 0;
    
    protected:
        ShapeConcept() = default;
        ShapeConcept(ShapeConcept const&) = default;
        ShapeConcept(ShapeConcept&&) noexcept = default;
        ShapeConcept& operator=(ShapeConcept&&) noexcept = default;
        ShapeConcept& operator=(ShapeConcept const&) = default;
    };

    template <typename ConcreteShape>
    class ShapeModel final: public ShapeConcept {
        public:
        explicit ShapeModel(ConcreteShape&& concrete_shape)
            // Copy-construct or move-construct the concrete type.
            : object_{std::forward<ConcreteShape>(concrete_shape)} {}

        void do_draw() const override {
            // Call free draw() on objects implementing the Shape interface.
            object_.draw();
        }

        [[nodiscard]] std::unique_ptr<ShapeConcept> clone() const override {
            return std::make_unique<ShapeModel>(*this);
        }

        private:
        ConcreteShape object_;
    };

    public:
    template <typename ConcreteShape>
    explicit Shape(ConcreteShape&& concrete_shape)
        : pimpl_{std::make_unique<ShapeModel<std::remove_reference_t<ConcreteShape>>>(
              std::forward<std::remove_reference_t<ConcreteShape>>(concrete_shape))} {}
    
    // Deep copy of the concrete shape object.
    Shape(Shape const& other) : pimpl_{other.pimpl_->clone()} {}

    // Deep copy of the concrete shape object.
    Shape& operator=(Shape const& rhs) {
        if (&rhs != this) {
            pimpl_ = rhs.pimpl_->clone();
        }
        return *this;
    }

    // unique_ptr is movable by default.
    Shape(Shape&&) noexcept = default;
    Shape& operator=(Shape&&) noexcept = default;

    std::unique_ptr<ShapeConcept> pimpl_; 

};