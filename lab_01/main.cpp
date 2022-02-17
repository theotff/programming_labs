#include <stdexcept>

class Point {
    private:
        int x_;
        int y_;

    public:
        explicit Point(int x_val, int y_val)
            :x_(x_val)
            ,y_(y_val)
        {}

        ~Point();

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
        
        int X() const {
            return x_;
        }

        int Y() const {
            return y_;
        }
};

class BrokenLine {
    private:
        Point* coords_;
        int points_;

    public:
        explicit BrokenLine(Point* coords, int points)
            :coords_(coords)
            ,points_(points)
        {
            //validate
        }

        ~BrokenLine();

        BrokenLine(const BrokenLine& bl)
            :coords_(bl.coords_)
            ,points_(bl.points_)
        {}

        BrokenLine operator=(const BrokenLine& bl) {
            coords_ = bl.coords_;
            points_ = bl.points_;
            return *this;
        }

        Point* Coords() {
            return coords_;
        }

        int Points() {
            return points_;
        }

        int Length() {
            //for point in points
        }
};

class ClosedBrokenLine: public BrokenLine {
    public:
        explicit ClosedBrokenLine(Point* coords, int points)
            :BrokenLine(coords, points)
        {
            if (!(coords[0] == coords[points - 1])) {
                throw std::invalid_argument("The line is not closed!");
            };
        }
};

class Polygon {
    private:
        Point* coords_;
        int points_;

    public:
        explicit Polygon(Point* coords, int points)
            :coords_(coords)
            ,points_(points)
        {
            // validate
        }

        ~Polygon();

        Polygon(const Polygon& p)
            :coords_(p.coords_)
            ,points_(p.points_)
        {}

        Polygon operator=(const Polygon& p) {
            coords_ = p.coords_;
            points_ = p.points_;
            return *this;
        }

        Point* Coords() {
            return coords_;
        }

        int Points() {
            return points_;
        }

        int Perimeter() {
            
        }

        float Area() {

        }
};

class Triangle: public Polygon {
    public:
        explicit Triangle(Point* coords)
            :Polygon(coords, 3)
        {}
    
    
};

int main() {
    return 0;
}