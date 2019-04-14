#include <utility>

// compound.h
// Header file for Compound Shape classes.

#ifndef CPS_COMPOUND_H
#define CPS_COMPOUND_H

#include "shapes.h"
#include <string>
#include <initializer_list>
#include <memory> //for std::unique_ptr
#include <vector>

// Compound Shapes

class Rotated : public Shape
{
public:
    Rotated(const Shape &s, double rotation);
    std::string getPostScriptCode() override;

private:
    double _origWidth;
    double _origHeight;
    double _rotation;
    std::string _postScriptCode;
};

class Scaled : public Shape
{
public:
    Scaled(const Shape &s, double horScale, double verScale);
    std::string getPostScriptCode() override;

private:
    double _origWidth;
    double _origHeight;
    double _horScale;
    double _verScale;
    std::string _postScriptCode;
};

class CompositeShape : public Shape
{
public:
    CompositeShape(std::vector<std::shared_ptr<Shape>> Shapes);
    std::string getPostScriptCode() override;

protected:
    virtual std::string moveToFirstPosition(std::shared_ptr<Shape> currentShape) = 0;
    std::vector<std::shared_ptr<Shape>> _shapes;

};

class Layered : public CompositeShape
{
public:
    Layered(std::vector<std::shared_ptr<Shape>> listOfShapes);
    std::string moveToFirstPosition(std::shared_ptr<Shape> currentShape) override;

private:
    std::vector<std::shared_ptr<Shape>> layeredShapes;
};

class Vertical : public CompositeShape
{
public:
    Vertical(std::vector<std::shared_ptr<Shape>> listOfShapes);
    std::string moveToFirstPosition(std::shared_ptr<Shape> currentShape) override;

private:
    std::vector<std::shared_ptr<Shape>> verticalShapes;
};

class Horizontal : public CompositeShape
{
public:
    Horizontal(std::vector<std::shared_ptr<Shape>> listOfShapes);
    std::string moveToFirstPosition(std::shared_ptr<Shape> currentShape) override;

private:
    std::vector<std::shared_ptr<Shape>> horizontalShapes;
};


#endif //CPS_COMPOUND_H
