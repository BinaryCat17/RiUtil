#pragma once

#include <ostream>

namespace rise {
    struct Width {
        Width() = default;

        explicit Width(unsigned int value) : value(value) {}

        bool operator==(Width rhs) const {
            return value == rhs.value;
        }

        bool operator!=(Width rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Width rhs) const {
            return value < rhs.value;
        }

        bool operator>(Width rhs) const {
            return rhs < *this;
        }

        bool operator<=(Width rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Width rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Width const &val) {
            os << val.value;
            return os;
        }

        unsigned value = 0;
    };

    struct Height {
        Height() = default;

        explicit Height(unsigned int value) : value(value) {}

        bool operator==(Height rhs) const {
            return value == rhs.value;
        }

        bool operator!=(Height rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Height rhs) const {
            return value < rhs.value;
        }

        bool operator>(Height rhs) const {
            return rhs < *this;
        }

        bool operator<=(Height rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Height rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Height const &val) {
            os << val.value;
            return os;
        }

        unsigned value = 0;
    };

    struct Depth {
        Depth() = default;

        explicit Depth(unsigned int value) : value(value) {}

        bool operator==(Depth rhs) const {
            return value == rhs.value;
        }

        bool operator!=(Depth rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Depth rhs) const {
            return value < rhs.value;
        }

        bool operator>(Depth rhs) const {
            return rhs < *this;
        }

        bool operator<=(Depth rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Depth rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Depth const &val) {
            os << val.value;
            return os;
        }

        unsigned value = 0;
    };

    struct Extent2D {
        Extent2D() = default;

        explicit Extent2D(Width width, Height height) : width(width), height(height) {}

        bool operator==(Extent2D rhs) const {
            return width == rhs.width &&
                   height == rhs.height;
        }

        bool operator!=(Extent2D rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Extent2D rhs) const {
            if (width < rhs.width)
                return true;
            if (rhs.width < width)
                return false;
            return height < rhs.height;
        }

        bool operator>(Extent2D rhs) const {
            return rhs < *this;
        }

        bool operator<=(Extent2D rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Extent2D rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Extent2D const &val) {
            os << val.width << " " << val.height;
            return os;
        }

        Width width;
        Height height;
    };

    struct Extent3D {
        Extent3D() = default;

        explicit Extent3D(Width width, Height height, Depth depth) : width(width), height(height),
                                                                     depth(depth) {}

        bool operator==(Extent3D rhs) const {
            return width == rhs.width &&
                   height == rhs.height &&
                   depth == rhs.depth;
        }

        bool operator!=(Extent3D rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Extent3D rhs) const {
            if (width < rhs.width)
                return true;
            if (rhs.width < width)
                return false;
            if (height < rhs.height)
                return true;
            if (rhs.height < height)
                return false;
            return depth < rhs.depth;
        }

        bool operator>(Extent3D rhs) const {
            return rhs < *this;
        }

        bool operator<=(Extent3D rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Extent3D rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Extent3D const &val) {
            os << val.width << " " << val.height << " " << val.depth;
            return os;
        }

        Width width;
        Height height;
        Depth depth;
    };

    struct X {
        X() = default;

        explicit X(unsigned int value) : value(value) {}

        bool operator==(X rhs) const {
            return value == rhs.value;
        }

        bool operator!=(X rhs) const {
            return !(rhs == *this);
        }

        bool operator<(X rhs) const {
            return value < rhs.value;
        }

        bool operator>(X rhs) const {
            return rhs < *this;
        }

        bool operator<=(X rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(X rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, X const &val) {
            os << val.value;
            return os;
        }

        unsigned value = 0;
    };

    struct Y {
        Y() = default;

        explicit Y(unsigned int value) : value(value) {}

        bool operator==(Y rhs) const {
            return value == rhs.value;
        }

        bool operator!=(Y rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Y rhs) const {
            return value < rhs.value;
        }

        bool operator>(Y rhs) const {
            return rhs < *this;
        }

        bool operator<=(Y rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Y rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Y const &val) {
            os << val.value;
            return os;
        }

        unsigned value = 0;
    };

    struct Z {
        Z() = default;

        explicit Z(unsigned int value) : value(value) {}

        bool operator==(Z rhs) const {
            return value == rhs.value;
        }

        bool operator!=(Z rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Z rhs) const {
            return value < rhs.value;
        }

        bool operator>(Z rhs) const {
            return rhs < *this;
        }

        bool operator<=(Z rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Z rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Z const &val) {
            os << val.value;
            return os;
        }

        unsigned value = 0;
    };

    struct Point2D {
        Point2D() = default;

        explicit Point2D(X x, Y y) : x(x), y(y) {}

        bool operator==(Point2D rhs) const {
            return x == rhs.x &&
                   y == rhs.y;
        }

        bool operator!=(Point2D rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Point2D rhs) const {
            if (x < rhs.x)
                return true;
            if (rhs.x < x)
                return false;
            return y < rhs.y;
        }

        bool operator>(Point2D rhs) const {
            return rhs < *this;
        }

        bool operator<=(Point2D rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Point2D rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Point2D const &val) {
            os << val.x << " " << val.y;
            return os;
        }

        X x;
        Y y;
    };

    struct Point3D {
        Point3D() = default;

        explicit Point3D(X x, Y y, Z z) : x(x), y(y), z(z) {}

        bool operator==(Point3D rhs) const {
            return x == rhs.x &&
                   y == rhs.y &&
                   z == rhs.z;
        }

        bool operator!=(Point3D rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Point3D rhs) const {
            if (x < rhs.x)
                return true;
            if (rhs.x < x)
                return false;
            if (y < rhs.y)
                return true;
            if (rhs.y < y)
                return false;
            return z < rhs.z;
        }

        bool operator>(Point3D rhs) const {
            return rhs < *this;
        }

        bool operator<=(Point3D rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Point3D rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Point3D const &val) {
            os << val.x << " " << val.y << " " << val.z;
            return os;
        }

        X x;
        Y y;
        Z z;
    };

    struct Version {
        Version() = default;

        explicit Version(unsigned int major, unsigned int minor = 0, unsigned int patch = 0,
                         unsigned int tweak = 0) : major(major), minor(minor), patch(patch), tweak(tweak) {}

        bool operator==(Version const &rhs) const {
            return major == rhs.major &&
                   minor == rhs.minor &&
                   patch == rhs.patch &&
                   tweak == rhs.tweak;
        }

        bool operator!=(Version const &rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Version const &rhs) const {
            if (major < rhs.major)
                return true;
            if (rhs.major < major)
                return false;
            if (minor < rhs.minor)
                return true;
            if (rhs.minor < minor)
                return false;
            if (patch < rhs.patch)
                return true;
            if (rhs.patch < patch)
                return false;
            return tweak < rhs.tweak;
        }

        bool operator>(Version const &rhs) const {
            return rhs < *this;
        }

        bool operator<=(Version const &rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Version const &rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Version const &version) {
            os << version.major << "." << version.minor << "."
               << version.patch << "." << version.tweak;
            return os;
        }

        unsigned major = 0;
        unsigned minor = 0;
        unsigned patch = 0;
        unsigned tweak = 0;
    };

    struct Size {
        Size() = default;

        explicit Size(size_t value) : value(value) {}

        bool operator==(Size rhs) const {
            return value == rhs.value;
        }

        bool operator!=(Size rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Size rhs) const {
            return value < rhs.value;
        }

        bool operator>(Size rhs) const {
            return rhs < *this;
        }

        bool operator<=(Size rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Size rhs) const {
            return !(*this < rhs);
        }

        Size& operator+=(Size rhs) {
            value += rhs.value;
            return *this;
        }

        friend Size operator+(Size lhs, Size rhs) {
            lhs += rhs;
            return lhs;
        }

        Size& operator-=(Size rhs) {
            value -= rhs.value;
            return *this;
        }

        friend Size operator-(Size lhs, Size rhs) {
            lhs -= rhs;
            return lhs;
        }

        Size& operator*=(Size rhs) {
            value *= rhs.value;
            return *this;
        }

        friend Size operator*(Size lhs, Size rhs) {
            lhs *= rhs;
            return lhs;
        }

        Size& operator/=(Size rhs) {
            value /= rhs.value;
            return *this;
        }

        friend Size operator/(Size lhs, Size rhs) {
            lhs /= rhs;
            return lhs;
        }

        Size& operator%=(Size rhs) {
            value %= rhs.value;
            return *this;
        }

        friend Size operator%(Size lhs, Size rhs) {
            lhs %= rhs;
            return lhs;
        }

        friend std::ostream &operator<<(std::ostream &os, Size const &val) {
            os << val.value;
            return os;
        }

        size_t value = 0;
    };

    struct Offset {
        Offset() = default;

        explicit Offset(size_t value) : value(value) {}

        bool operator==(Offset rhs) const {
            return value == rhs.value;
        }

        bool operator!=(Offset rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Offset rhs) const {
            return value < rhs.value;
        }

        bool operator>(Offset rhs) const {
            return rhs < *this;
        }

        bool operator<=(Offset rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Offset rhs) const {
            return !(*this < rhs);
        }

        Offset& operator+=(Offset rhs) {
            value += rhs.value;
            return *this;
        }

        friend Offset operator+(Offset lhs, Offset rhs) {
            lhs += rhs;
            return lhs;
        }

        Offset& operator-=(Offset rhs) {
            value -= rhs.value;
            return *this;
        }

        friend Offset operator-(Offset lhs, Offset rhs) {
            lhs -= rhs;
            return lhs;
        }

        Offset& operator*=(Offset rhs) {
            value *= rhs.value;
            return *this;
        }

        friend Offset operator*(Offset lhs, Offset rhs) {
            lhs *= rhs;
            return lhs;
        }

        Offset& operator/=(Offset rhs) {
            value /= rhs.value;
            return *this;
        }

        friend Offset operator/(Offset lhs, Offset rhs) {
            lhs /= rhs;
            return lhs;
        }

        Offset& operator%=(Offset rhs) {
            value %= rhs.value;
            return *this;
        }

        friend Offset operator%(Offset lhs, Offset rhs) {
            lhs %= rhs;
            return lhs;
        }

        friend std::ostream &operator<<(std::ostream &os, Offset const &val) {
            os << val.value;
            return os;
        }

        size_t value = 0;
    };

    struct Alignment {
        Alignment() = default;

        explicit Alignment(size_t value) : value(value) {}

        bool operator==(Alignment rhs) const {
            return value == rhs.value;
        }

        bool operator!=(Alignment rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Alignment rhs) const {
            return value < rhs.value;
        }

        bool operator>(Alignment rhs) const {
            return rhs < *this;
        }

        bool operator<=(Alignment rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Alignment rhs) const {
            return !(*this < rhs);
        }

        Alignment& operator+=(Alignment rhs) {
            value += rhs.value;
            return *this;
        }

        friend Alignment operator+(Alignment lhs, Alignment rhs) {
            lhs += rhs;
            return lhs;
        }

        Alignment& operator-=(Alignment rhs) {
            value -= rhs.value;
            return *this;
        }

        friend Alignment operator-(Alignment lhs, Alignment rhs) {
            lhs -= rhs;
            return lhs;
        }

        Alignment& operator*=(Alignment rhs) {
            value *= rhs.value;
            return *this;
        }

        friend Alignment operator*(Alignment lhs, Alignment rhs) {
            lhs *= rhs;
            return lhs;
        }

        Alignment& operator/=(Alignment rhs) {
            value /= rhs.value;
            return *this;
        }

        friend Alignment operator/(Alignment lhs, Alignment rhs) {
            lhs /= rhs;
            return lhs;
        }

        Alignment& operator%=(Alignment rhs) {
            value %= rhs.value;
            return *this;
        }

        friend Alignment operator%(Alignment lhs, Alignment rhs) {
            lhs %= rhs;
            return lhs;
        }

        friend std::ostream &operator<<(std::ostream &os, Alignment const &val) {
            os << val.value;
            return os;
        }

        size_t value = 0;
    };

    struct Index {
        Index() = default;

        explicit Index(size_t value) : value(value) {}

        bool operator==(Index rhs) const {
            return value == rhs.value;
        }

        bool operator!=(Index rhs) const {
            return !(rhs == *this);
        }

        bool operator<(Index rhs) const {
            return value < rhs.value;
        }

        bool operator>(Index rhs) const {
            return rhs < *this;
        }

        bool operator<=(Index rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(Index rhs) const {
            return !(*this < rhs);
        }

        Index& operator+=(Index rhs) {
            value += rhs.value;
            return *this;
        }

        friend Index operator+(Index lhs, Index rhs) {
            lhs += rhs;
            return lhs;
        }

        Index& operator-=(Index rhs) {
            value -= rhs.value;
            return *this;
        }

        friend Index operator-(Index lhs, Index rhs) {
            lhs -= rhs;
            return lhs;
        }

        Index& operator*=(Index rhs) {
            value *= rhs.value;
            return *this;
        }

        friend Index operator*(Index lhs, Index rhs) {
            lhs *= rhs;
            return lhs;
        }

        Index& operator/=(Index rhs) {
            value /= rhs.value;
            return *this;
        }

        friend Index operator/(Index lhs, Index rhs) {
            lhs /= rhs;
            return lhs;
        }

        Index& operator%=(Index rhs) {
            value %= rhs.value;
            return *this;
        }

        friend Index operator%(Index lhs, Index rhs) {
            lhs %= rhs;
            return lhs;
        }

        friend std::ostream &operator<<(std::ostream &os, Index const &val) {
            os << val.value;
            return os;
        }

        size_t value = 0;
    };

    struct MemData {
        explicit MemData(const *data, const Size &size) : data(data), size(size) {}

        void* data;
        Size size;
    };
}