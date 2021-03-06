#pragma once

#include <sstream>

class Format
{
    public:
        virtual ~Format();
        void clear();

        virtual std::string getBaseLayer()=0;
        virtual void beginPolygon(std::string layer, bool isFirst);
        virtual void endPolygon(std::string layer, bool isFirst);
        virtual void beginPath();
        virtual void addPoint(double x, double y)=0;
        virtual bool supportsCircle();
        virtual void addCircle(std::string layer, double x, double y, double r);
        virtual void endPath();
        virtual std::string output()=0;
        
        virtual double getXRatio();
        virtual double getYRatio();
        void registerPoint(double x, double y);

    protected:
        std::stringstream stream;
        bool hasM;
        double xMin, yMin, xMax, yMax;
};
