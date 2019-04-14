Refactored Project 2 for Assignment 5. Got rid of rainbowball, spacer, human from project 2.

# C++ to PostScript Library
Nami Kim
For UAF CS372 Software Construction Spring 2019.

### Description:
* This is a C++ to PostScript library that allows users to define shapes from our shape language in C++, and output drawings of the shapes in PostScript.  
* Compiling the listed files will output sample PostScript code to 'testShapes.ps' which can be interpreted by a PostScript viewer.

### Shape Language + Examples:
#### Basic Shapes:
* **Circle**(double **radius**) - Creates a circle with a given radius.
* **Polygon**(int **numSides**, double **sideLength**) - Creates a polygon with given number of sides and side length.
* **Rectangle**(double **width**, double **height**) - Creates a rectangle with given width and height.
* **Square**(double **sideLength**) - Creates a square with given side length.
* **Triangle**(double **sideLength**) - Creates a triangle with given side length.
#### Compound Shapes:
Compound shapes can be built from basic shapes or compound shapes themselves.
* **Rotated**(Shape **shape**, double **RotationAngle**) - Creates a given shape rotated counterclockwise by the given angle.
* **Scaled**(Shape **shape**, double **horScale**, double **vertScale**) - Creates a given shape scaled horizontally and vertically by the given factors.  

#### Output to PostScript File Example:
Create as many shape objects from the shape language that you want to draw.
```Circle circle(20);```  
Then, create a page object to draw the shapes to the page at a specified point.
```
Circle circle(20);
Page shapePage;
shapePage.drawToPage(circle, 40, 40);
```
Finally, create a PSOutput object to add the page drawn to and specify where to output PostScript code (must be .ps file).
```
PSOutput output;
output.addPage(shapePage);
output.PSOutput_File("shapes.ps");
```

### Files:
* cps.cpp - Main File. Includes a shapes-to-PostScript testing/drawing strategy with page.cpp/h.
* shapes.cpp/h - Source/Header file for Shape classes. Contains derived basic shapes.
* compound.cpp/h - Source/Header file for Shape classes. Contains derived compound shapes and derived composite shapes.
* page.cpp/h - Source/Header file for Page class. Contains framework for drawing shapes to a page in PostScript.
