#pragma once


constexpr unsigned int BITS_PER_UINT = sizeof(unsigned long) * 8;

using uint = unsigned int;
using sint = int;

namespace apa
{
	struct BigInt
	{
		
	};

	struct Rational
	{
		
	};

	struct BigFloat
	{
		
	};

	namespace fixed_precision
	{
		struct Int
		{
			
		};

		struct Rational
		{
			
		};

		struct Float
		{
			
		};
	}

	namespace utils
	{
		template<typename elem_t>
		struct Array
		{
			
		};

		template<typename numeric_t>
		struct Complex
		{
			numeric_t r, i;

			Complex& operator+=(const Complex& rhs)
			{
				r += rhs.r;
				i += rhs.i;
				return *this;
			}

			friend Complex operator+(Complex lhs, const Complex& rhs)
			{
				lhs += rhs;
				return lhs;
			}

			Complex& operator-=(const Complex& rhs)
			{
				r -= rhs.r;
				i -= rhs.i;
				return *this;
			}

			friend Complex operator-(Complex lhs, const Complex& rhs)
			{
				lhs -= rhs;
				return lhs;
			}

			Complex& operator*=(const Complex& rhs)
			{
				numeric_t temp = r * rhs.r - i * rhs.i;
				i = r * rhs.i + i * rhs.r;
				r = temp;
				return *this;
			}

			friend Complex operator*(Complex lhs, const Complex& rhs)
			{
				lhs *= rhs;
				return lhs;
			}

			Complex conjugate() const
			{
				return Complex(r, -i);
			}

			numeric_t square_magnitude() const
			{
				return r * r + i * i;
			}

			Complex& operator/=(const numeric_t& rhs)
			{
				r /= rhs;
				i /= rhs;
				return *this;
			}

			friend Complex operator/(Complex lhs, const numeric_t& rhs)
			{
				lhs /= rhs;
				return lhs;
			}

			Complex& operator/=(const Complex& rhs)
			{
				this *= rhs.conjugate();
				this /= rhs.square_magnitude();
				return *this;
			}

			friend Complex operator/(Complex lhs, const Complex& rhs)
			{
				lhs /= rhs;
				return lhs;
			}

			inline bool operator==(const Complex& lhs, const Complex& rhs) { return lhs.r == rhs.r && lhs.i == rhs.i; }
			inline bool operator!=(const Complex& lhs, const Complex& rhs) { return lhs.r != rhs.r && lhs.i != rhs.i; }
			inline bool operator< (const Complex& lhs, const Complex& rhs) { return lhs.square_magnitude() <  rhs.square_magnitude(); }
			inline bool operator> (const Complex& lhs, const Complex& rhs) { return lhs.square_magnitude() >  rhs.square_magnitude(); }
			inline bool operator<=(const Complex& lhs, const Complex& rhs) { return lhs.square_magnitude() <= rhs.square_magnitude(); }
			inline bool operator>=(const Complex& lhs, const Complex& rhs) { return lhs.square_magnitude() >= rhs.square_magnitude(); }
			auto operator<=>(const Complex&) const = default;
		};
	}



}
