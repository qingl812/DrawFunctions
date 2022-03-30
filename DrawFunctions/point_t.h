#pragma once

namespace microlife {

// 用于表示坐标的键值对(x, y)
// 也可以用来表示矩阵大小
struct point_t {
	size_t x; // 横坐标
	size_t y; // 纵坐标

	point_t() = default;

	point_t(size_t x, size_t y) :x(x), y(y) {}
};
} // namespace microlife