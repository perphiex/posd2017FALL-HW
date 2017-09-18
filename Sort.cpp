#include "include/Sort.h"

void Sort::sortByIncreasingPerimeter(std::list<Shape *> *shapeList)
{
    shapeList->sort(
        [](const Shape *shape1, const Shape *shape2) {
            return shape1->perimeter() < shape2->perimeter();
        });
}

void Sort::sortByDecreasingPerimeter(std::list<Shape *> *shapeList)
{
    sortByIncreasingPerimeter(shapeList);
    shapeList->reverse();
}

void Sort::sortByIncreasingArea(std::list<Shape *> *shapeList)
{
    shapeList->sort(
        [](const Shape *shape1, const Shape *shape2) {
            return shape1->area() < shape2->area();
        });
}

void Sort::sortByDecreasingArea(std::list<Shape *> *shapeList)
{
    sortByIncreasingArea(shapeList);
    shapeList->reverse();
}

void Sort::sortByIncreasingCompactness(std::list<Shape *> *shapeList)
{
    shapeList->sort(
        [](const Shape *shape1, const Shape *shape2) {
            return shape1->area() / shape1->perimeter() < shape2->area() / shape2->perimeter();
        });
}