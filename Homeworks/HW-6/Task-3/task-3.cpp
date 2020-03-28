#include <iostream>
#include <cmath>
#include <algorithm>

struct Point {
    int x;
    int y;
    double distance;
};

struct PointsCompare {
    const bool operator() (const Point& lhs, const Point& rhs) {
        if (lhs.distance > rhs.distance) {
            return true;
        }
        else if (lhs.distance == rhs.distance && lhs.x > rhs.x) {
            return true;
        }
        else if (lhs.distance == rhs.distance && lhs.x == rhs.x && lhs.y > rhs.y) {
            return true;
        }
        else return false;
    }
};

class minHeap {
    Point* points;
    int number;

public:
    minHeap(Point* points, int number) {
        this->points = points;
        this->number = number;

        std::make_heap(this->points, this->points + number, PointsCompare());
    }

    Point pop() {
        Point toPop = points[0];

        std::pop_heap(points, points + number, PointsCompare());
        number--;

        return toPop;
    }
};

void calculateClosest() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int number;
    std::cin >> number;

    int k;
    std::cin >> k;

    Point* inputs = new Point[number];
    Point input;

    for (int i = 0; i < number; i++) {
        std::cin >> input.x >> input.y;
        input.distance = (double)input.x * input.x;
        input.distance += (double)input.y * input.y;

        inputs[i] = input;
    }

    minHeap points(inputs, number);

    for (int i = 0; i < k; i++) {
        Point output = points.pop();

        std::cout << output.x << " " << output.y << std::endl;
    }

    delete[] inputs;
}

int main() {
    calculateClosest();

    return 0;
}
