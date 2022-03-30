#pragma once

#include "point_t.h"

#include <ostream>
#include <assert.h>


namespace microlife {

// ����
template<typename T>
class canvas
{
public:
	using point_t = microlife::point_t;
	using ostream = std::ostream;
	using to_char_f = const char* (*)(const T&); // ��Ԫ�� T ת��Ϊ�ַ����ĺ���

public:
	// ��ȣ��߶ȣ���ʼֵ
	canvas(size_t width, size_t height, const T& value) :
		m_width(width),
		m_height(height),
		m_element(new T[width * height]) {
		std::fill(m_element, m_element + width * height, value);
	}

	~canvas() { delete[] m_element; }

	const T& get(size_t x, size_t y) const { return get_ref(x, y); }
	const T& get(const point_t& p) const { return get_ref(p.x, p.y); }

	T& get(size_t x, size_t y) { return get_ref(x, y); }
	T& get(const point_t& p) { return get_ref(p.x, p.y); }

	void set(const point_t& p, const T& v) { get_ref(p.x, p.y) = v; }
	void set(size_t x, size_t y, const T& v) { get_ref(x, y) = v; }

	size_t width() const { return m_width; }
	size_t height() const { return m_height; }
	point_t size() const { return { m_width, m_height }; }

	// ������� p �ĺϷ���
	bool check(size_t x, size_t y) const {
		return x >= 0 && x < width() && y >= 0 && y < height();
	}
	bool check(const point_t& p) const { return check(p.x, p.y); }

	// callback Ϊ��Ԫ�� T ת��Ϊ�ַ����ĺ���
	void print(ostream& os, to_char_f func) const {
		for (size_t x = 0; x < m_width; x++) {
			for (size_t y = 0; y < m_height; y++) {
				os << func(get_ref(x, y));
			}
			os << '\n';
		}
	}

public:
	// ���ض�Ӧ����Ԫ�ص�����
	T& operator()(size_t x, size_t y) { return get_ref(x, y); }

	// ���ض�Ӧ����Ԫ�ص�����
	T& operator[](const point_t& p) { return get_ref(p.x, p.y); }

private:
	size_t m_width;		// �������
	size_t m_height;	// �����߶�
	T* m_element;		// ����Ԫ��

private:
	// ��ȡ��Ӧ����Ԫ�ص�����
	T& get_ref(size_t x, size_t y) {
		assert(check(x, y));
		return m_element[x + y * m_width];
	}

	const T& get_ref(size_t x, size_t y) const {
		assert(check(x, y));
		return m_element[x + y * m_width];
	}
};
} // namespace microlife
