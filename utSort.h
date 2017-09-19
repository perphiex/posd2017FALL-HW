#ifndef UTSORT_H
#define UTSORT_H

#include <iostream>
#include <list>
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

void initTestData(std::list<Shape *> *shapeList)
{
    shapeList->push_back(new Rectangle(0, 0, 1, 20, "a20, p42"));
    shapeList->push_back(new Rectangle(0, 0, 1, 10, "a10, p22"));
    shapeList->push_back(new Rectangle(0, 0, 1, 5, "a5, p12"));
    shapeList->push_back(new Circle(0, 0, 1, "a3.1415, p6.2831"));
    shapeList->push_back(new Circle(0, 0, 2, "a12.5663, p12.5663"));
    shapeList->push_back(new Circle(0, 0, 3, "a28.2743, p18.8495"));
    shapeList->push_back(new Triangle({0, 0}, {6, 0}, {3, 1}, "a3, p12.325"));
    shapeList->push_back(new Triangle({0, 0}, {6, 0}, {3, 2}, "a6, p13.211"));
    shapeList->push_back(new Triangle({0, 0}, {6, 0}, {3, 3}, "a9, p14.485"));
}

void deleteShapeList(std::list<Shape *> *shapeList)
{
    for (auto item : shapeList)
        delete item;
    delete shapeList;
}

TEST(Sort, sortByIncreasingPerimeter)
{
    std::list<Shape *> *shapeList = new std::list<Shape *>();
    initTestData(shapeList);
    Sort::sortByIncreasingPerimeter(shapeList);
    std::list<Shape *>::iterator it = shapeList->begin();

    ASSERT_EQ((*(it++))->getShapeName(), "a3.1415, p6.2831");
    ASSERT_EQ((*(it++))->getShapeName(), "a5, p12");
    ASSERT_EQ((*(it++))->getShapeName(), "a3, p12.325");
    ASSERT_EQ((*(it++))->getShapeName(), "a12.5663, p12.5663");
    ASSERT_EQ((*(it++))->getShapeName(), "a6, p13.211");
    ASSERT_EQ((*(it++))->getShapeName(), "a9, p14.485");
    ASSERT_EQ((*(it++))->getShapeName(), "a28.2743, p18.8495");
    ASSERT_EQ((*(it++))->getShapeName(), "a10, p22");
    ASSERT_EQ((*(it++))->getShapeName(), "a20, p42");

    deleteShapeList(shapeList);
}

TEST(Sort, sortByDecreasingPerimeter)
{
    std::list<Shape *> *shapeList = new std::list<Shape *>();
    initTestData(shapeList);
    Sort::sortByDecreasingPerimeter(shapeList);
    std::list<Shape *>::iterator it = shapeList->begin();

    ASSERT_EQ((*(it++))->getShapeName(), "a20, p42");
    ASSERT_EQ((*(it++))->getShapeName(), "a10, p22");
    ASSERT_EQ((*(it++))->getShapeName(), "a28.2743, p18.8495");
    ASSERT_EQ((*(it++))->getShapeName(), "a9, p14.485");
    ASSERT_EQ((*(it++))->getShapeName(), "a6, p13.211");
    ASSERT_EQ((*(it++))->getShapeName(), "a12.5663, p12.5663");
    ASSERT_EQ((*(it++))->getShapeName(), "a3, p12.325");
    ASSERT_EQ((*(it++))->getShapeName(), "a5, p12");
    ASSERT_EQ((*(it++))->getShapeName(), "a3.1415, p6.2831");

    deleteShapeList(shapeList);
}

TEST(Sort, sortByIncreasingArea)
{
    std::list<Shape *> *shapeList = new std::list<Shape *>();
    initTestData(shapeList);
    Sort::sortByIncreasingArea(shapeList);
    std::list<Shape *>::iterator it = shapeList->begin();

    ASSERT_EQ((*(it++))->getShapeName(), "a3, p12.325");
    ASSERT_EQ((*(it++))->getShapeName(), "a3.1415, p6.2831");
    ASSERT_EQ((*(it++))->getShapeName(), "a5, p12");
    ASSERT_EQ((*(it++))->getShapeName(), "a6, p13.211");
    ASSERT_EQ((*(it++))->getShapeName(), "a9, p14.485");
    ASSERT_EQ((*(it++))->getShapeName(), "a10, p22");
    ASSERT_EQ((*(it++))->getShapeName(), "a12.5663, p12.5663");
    ASSERT_EQ((*(it++))->getShapeName(), "a20, p42");
    ASSERT_EQ((*(it++))->getShapeName(), "a28.2743, p18.8495");

    deleteShapeList(shapeList);
}

TEST(Sort, sortByDecreasingArea)
{
    std::list<Shape *> *shapeList = new std::list<Shape *>();
    initTestData(shapeList);
    Sort::sortByDecreasingArea(shapeList);
    std::list<Shape *>::iterator it = shapeList->begin();

    ASSERT_EQ((*(it++))->getShapeName(), "a28.2743, p18.8495");
    ASSERT_EQ((*(it++))->getShapeName(), "a20, p42");
    ASSERT_EQ((*(it++))->getShapeName(), "a12.5663, p12.5663");
    ASSERT_EQ((*(it++))->getShapeName(), "a10, p22");
    ASSERT_EQ((*(it++))->getShapeName(), "a9, p14.485");
    ASSERT_EQ((*(it++))->getShapeName(), "a6, p13.211");
    ASSERT_EQ((*(it++))->getShapeName(), "a5, p12");
    ASSERT_EQ((*(it++))->getShapeName(), "a3.1415, p6.2831");
    ASSERT_EQ((*(it++))->getShapeName(), "a3, p12.325");

    deleteShapeList(shapeList);
}

TEST(Sort, sortByIncreasingCompactness)
{
    std::list<Shape *> *shapeList = new std::list<Shape *>();
    initTestData(shapeList);
    Sort::sortByIncreasingCompactness(shapeList);
    std::list<Shape *>::iterator it = shapeList->begin();

    ASSERT_EQ((*(it++))->getShapeName(), "a3, p12.325");
    ASSERT_EQ((*(it++))->getShapeName(), "a5, p12");
    ASSERT_EQ((*(it++))->getShapeName(), "a6, p13.211");
    ASSERT_EQ((*(it++))->getShapeName(), "a10, p22");
    ASSERT_EQ((*(it++))->getShapeName(), "a20, p42");
    ASSERT_EQ((*(it++))->getShapeName(), "a3.1415, p6.2831");
    ASSERT_EQ((*(it++))->getShapeName(), "a9, p14.485");
    ASSERT_EQ((*(it++))->getShapeName(), "a12.5663, p12.5663");
    ASSERT_EQ((*(it++))->getShapeName(), "a28.2743, p18.8495");

    deleteShapeList(shapeList);
}

#endif
