class Rectangle {
public:
    Rectangle(int x, int y, double width, double height);
    ~Rectangle();
    double getPerimeter();
    double getArea();
    void translate(int dx, int dy);
    void scale(double factor);
    void print();
private:
    int x, y;
    double width, height;
};