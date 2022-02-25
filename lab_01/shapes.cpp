#include <stdexcept>
#include <math.h>
#include <vector>
#include <iostream>

class Point {
    private:
        int x_;
        int y_;

    public:
        explicit Point(int x, int y)
            :x_(x)
            ,y_(y)
        {}

        ~Point() {}

        Point(const Point& p)
            :x_(p.x_)
            ,y_(p.y_)
        {}

        Point& operator=(const Point& p) {
            x_ = p.x_;
            y_ = p.y_;
            return *this;
        }

        bool operator==(const Point& p) {
            if ((x_ == p.x_) && (y_ == p.y_)) {
                return true;
            };
            return false;
        }
        
        int get_x() const {
            return this->x_;
        }

        int get_y() const {
            return this->y_;
        }
};

class Polyline {
    private:
        std::vector<Point> coords_;
        int points_;

    public:
        explicit Polyline(std::vector<Point> coords, int points)
            :coords_(coords)
            ,points_(points)
        {
            if (coords.size() != points) {
                throw std::invalid_argument("The number of points doesn't match coordniates!");
            };
            for (int i = 0; i < points - 2; i++) {
                if (triangle_area(coords_[i], coords_[i+1], coords_[i+2]) != 0) {
                    throw std::invalid_argument("The polyline is straight!");
                };
            };
        }

        ~Polyline() {}

        Polyline(const Polyline& bl)
            :coords_(bl.coords_)
            ,points_(bl.points_)
        {}

        Polyline operator=(const Polyline& bl) {
            coords_ = bl.coords_;
            points_ = bl.points_;
            return *this;
        }

        std::vector<Point> get_cooords() const {
            return this->coords_;
        }

        int get_points() const {
            return this->points_;
        }

        float length() {
            float len = 0.0;
            for (int i = 0; i < points_ - 1; i++) {
                std::cout << coords_[i].get_x() << "\n";
                int ci1x = coords_[i].get_x();
                int ci2x = coords_[i+1].get_x();
                int ci1y = coords_[i].get_y();
                int ci2y = coords_[i+1].get_y();
                len += std::pow(std::pow((ci1x - ci2x), 2) + std::pow((ci1y - ci2y), 2), 0.5);
            };
            return len;
        }

        float triangle_area(Point p1, Point p2, Point p3) {
            float area;
            int p1x = p1.get_x(); 
            int p2x = p2.get_x();
            int p3x = p3.get_x();
            int p1y = p1.get_y();
            int p2y = p2.get_y();
            int p3y = p3.get_y();

            float area = (p1y + p2y) * (p1x - p2x) + (p2y + p3y) * (p2x - p3x) + (p3y + p1y) * (p3x - p1x);
            return area;
        }
};

class ClosedPolyline: public Polyline {
    public:
        explicit ClosedPolyline(std::vector<Point> coords, int points)
            :Polyline(coords, points)
        {
            if (!(coords[0] == coords[points - 1])) {
                throw std::invalid_argument("The line is not closed!");
            };
        }
};

class Polygon: public ClosedPolyline {
    public:
        explicit Polygon(std::vector<Point> coords, int points)
            :ClosedPolyline(coords, points)
        {
            if (points < 4) {
                throw std::invalid_argument("Cant't make a polygon from 2 points!");
            };
        }

        float perimeter() {
            return this->length();
        }

        float area() {
            float area = 0.0;
            for (int i = 0; i < get_points() - 1; i++) {
                std::vector<Point> coords = get_cooords();
                area += (coords[i].get_y() + coords[i+1].get_y()) * (coords[i].get_x() - coords[i+1].get_x());
            }
            return std::abs(area / 2.0);
        }
};

class Triangle: public Polygon {
    public:
        explicit Triangle(std::vector<Point> coords)
            :Polygon(coords, 4)
        {}
};

class Trapezoid: public Polygon {
    public:
        explicit Trapezoid(std::vector<Point> coords)
            :Polygon(coords, 4)
        {
            std::vector<float> angles(4, 0.0);
            for (int i = 0; i < get_points() - 1; i++) {
                angles[i] = (float)(coords[i].get_y() - coords[i+1].get_y())/(float)(coords[i].get_x() - coords[i+1].get_x());
            };

            if ((angles[0] == angles[2]) || (angles[1] != angles[3])) {
                throw std::invalid_argument("Not a trapezoid!");
            }
        }
};

class RegularPolygon: public Polygon {
    public:
        explicit RegularPolygon(std::vector<Point> coords, int points)
            :Polygon(coords, points)
        {
            float area;
            for (int i = 0; i < points - 2; i++) {
                if (i == 0) {
                    area = triangle_area(coords[i], coords[i+1], coords[i+2]);
                } else {
                    if (area != triangle_area(coords[i], coords[i+1], coords[i+2])) {
                        throw std::invalid_argument("The polygon is not regular!");
                    };
                }
            }
        }
};

int main() {
    int points = 4;
    Point p1 = Point(0, 0);
    Point p2 = Point(3, 3);
    Point p3 = Point(0, 6);
    Point p4 = Point(0, 0);

    std::vector<Point> coords {
        p1,
        p2,
        p3,
        p4,
    };

    Triangle polytest = Triangle(coords);
    float area = polytest.area();
    std::cout << area << "\n";

    return 0;
}
