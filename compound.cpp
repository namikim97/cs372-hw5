// compound.cpp
// Source file for Compound Shape classes.

#include "compound.h"
#include <string>
using std::string;
using std::to_string;
#include <utility>
using std::move;


Rotated::Rotated(const Shape &s, double rotation):_rotation(rotation)
{
    const double radians = (_rotation * 2.0 * M_PI)/360.0;

    // _postScriptCode = s.getPostScriptCode();
    _origWidth = s.getWidth();
    _origHeight = s.getHeight();

    setWidth(abs(_origWidth * cos(radians) + _origHeight * sin(radians)));
    setHeight(abs(_origWidth * sin(radians) + _origHeight * cos(radians)));
}

string Rotated::getPostScriptCode() 
{
    string retPSCode;

    retPSCode = to_string((int)_rotation) + " rotate\n" + _postScriptCode;

    return retPSCode;
}

Scaled::Scaled(const Shape &s, double horScale, double verScale)
                :_horScale(horScale), _verScale(verScale), 
                _origWidth(s.getWidth()), _origHeight(s.getHeight())
{
    // _postScriptCode = s.getPostScriptCode())
    setWidth(_origWidth * horScale);
    setHeight(_origHeight * verScale);
}

string Scaled::getPostScriptCode() 
{
    string retPSCode;

    retPSCode = to_string(_horScale) + " " + to_string(_verScale) +
                " scale\n" + _postScriptCode;

    return retPSCode;
}

CompositeShape::CompositeShape(std::vector<std::shared_ptr<Shape>> Shapes)
{
    Shapes = _shapes;
}

string CompositeShape::getPostScriptCode()
{
    string retPSCode = "";

    for (int i=0; i<_shapes.size(); ++i)
    {
        retPSCode += moveToFirstPosition(_shapes[i]);
        retPSCode += _shapes[i] -> getPostScriptCode();
        retPSCode += moveToFirstPosition(_shapes[i]);
    }

    return retPSCode;
}

Layered::Layered(std::vector<std::shared_ptr<Shape>> listOfShapes):CompositeShape(listOfShapes)
{
    layeredShapes = move(listOfShapes);
    _height = 0;
    _width = 0;

    for(int i=0; i<layeredShapes.size(); ++i)
    {
        if(_width < layeredShapes[i]->_width)
        {
            _width = layeredShapes[i]->_width;
        }
        if(_height < layeredShapes[i]->_height)
        {
            _height = layeredShapes[i]->_height;
        }
    }
}

string Layered::moveToFirstPosition(std::shared_ptr<Shape> currentShape)
{
    return "0 0 translate\n";
}

Vertical::Vertical(std::vector<std::shared_ptr<Shape>> listOfShapes):CompositeShape(listOfShapes)
{
    verticalShapes = move(listOfShapes);
    _height = 0;
    _width = 0;

    for(int i=0; i<verticalShapes.size(); ++i)
    {
        _height += move((verticalShapes[i]->_height) + 1);
        if(_width < verticalShapes[i]->_width)
        {
            _width = verticalShapes[i]->_width;
        }
    }
}

string Vertical::moveToFirstPosition(std::shared_ptr<Shape> currentShape)
{
    return "0 " + to_string(currentShape->_height / 2) + " translate\n";
}

Horizontal::Horizontal(std::vector<std::shared_ptr<Shape>> listOfShapes):CompositeShape(listOfShapes)
{
    horizontalShapes = move(listOfShapes);
    _height = 0;
    _width = 0;

    for(int i=0; i<horizontalShapes.size(); ++i)
    {
        _width += move((horizontalShapes[i]->_width) +1);
        if(_height < horizontalShapes[i]->_height)
        {
            _height = horizontalShapes[i]->_height;
        }
    }
}

string Horizontal::moveToFirstPosition(std::shared_ptr<Shape> currentShape)
{
    return to_string(currentShape->_width / 2) + " 0 translate\n";
}

