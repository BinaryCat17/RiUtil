#pragma once

#include <ostream>
#include <vector>

namespace rise {
    using Width = unsigned;

    using Height = unsigned;

    using Depth = unsigned;

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

    using X = unsigned;

    using Y = unsigned;

    using Z = unsigned;

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
                unsigned int tweak = 0) : major(major), minor(minor), patch(patch),
                                          tweak(tweak) {}

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

    using Size = size_t;

    using Offset = size_t;

    using Alignment = size_t;

    using Index = size_t;

    struct MemData {
        explicit MemData(void *data, const Size &size) : data(data), size(size) {}

        template<typename T>
        explicit MemData(std::vector<T> &vec) : data(vec.data()), size(vec.size() * sizeof(T)) {}

        void *data;
        Size size;
    };

    struct NonCopyable {
        NonCopyable() = default;

        NonCopyable(NonCopyable const &) = delete;

        NonCopyable(NonCopyable &&) = default;

        NonCopyable& operator=(NonCopyable const &) = delete;

        NonCopyable& operator=(NonCopyable &&) = default;
    };

    template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };

    template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;
}
