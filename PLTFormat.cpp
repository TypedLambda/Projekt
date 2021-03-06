#include "PLTFormat.h"
        
std::string PLTFormat::getBaseLayer()
{
    return "1";
}

std::string PLTFormat::output()
{
    std::stringstream outstr;
        
    outstr << stream.str();		
    outstr << "SP0;" << std::endl;

    return outstr.str();
}

void PLTFormat::beginPolygon(std::string layer, bool isFirst)
{
    stream << "SP" << layer << ";" << std::endl;
}

void PLTFormat::endPolygon(std::string layer, bool isFirst)
{
}

void PLTFormat::beginPath()
{
    firstPoint = true;
}

void PLTFormat::addPoint(double x, double y)
{
    if (firstPoint) {
        fX = x;
        fY = y;
        firstPoint = false;
        stream << "PU";
    } else {
        stream << "PD";
    }

    stream << (int)x << " " << (int)y << " ";
    stream << ";" << std::endl;
}

void PLTFormat::endPath()
{
    if (!firstPoint) {
        stream << "PD" << (int)fX << " " << (int)fY << " " << std::endl;
    }
}


double PLTFormat::getXRatio()
{
    return 40.0/1000.0;
}

double PLTFormat::getYRatio()
{
    return 40.0/1000.0;
}
