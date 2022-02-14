class Point {
    private:
        int x_;
        int y_;

    public:
        explicit Point(int x_val, int y_val)
            :x_(x_val)
            ,y_(y_val)
        {}

        Point(const Point& p)
            :x_(p.x_)
            ,y_(p.y_)
        {}

        Point& operator=(const Point& p) {
            x_ = p.x_;
            y_ = p.y_;
            return *this;
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

    public:
        explicit BrokenLine(Point* coords)
            :coords_(coords)
        {}

        BrokenLine(const BrokenLine& bl)
            :coords_(bl.coords_)
        {}

        BrokenLine operator=(const BrokenLine& bl) {
            coords_ = bl.coords_;
            return *this;
        }

        Point* Coords() {
            return coords_;
        }
};

int main() {
    return 0;
}