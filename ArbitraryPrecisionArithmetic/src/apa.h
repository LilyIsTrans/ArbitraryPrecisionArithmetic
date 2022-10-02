#pragma once


#include <cstdint>



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
		template<size_t bytes>
		struct Int
		{
			
		};

		template<size_t bytes>
		struct UInt
		{
			static constexpr unsigned int UINTS = bytes / sizeof(uint32_t);
			uint32_t data[UINTS];

			UInt& operator+=(const UInt& rhs)
			{
				uint32_t carry = 0;
				uint32_t sum = 0;
				uint64_t full_sum = 0;
				for (size_t i = 0; i < UINTS; i++)
				{
					full_sum = (uint64_t)data[i] + (uint64_t)rhs.data[i] + (uint64_t)carry;
					carry = (uint32_t)((full_sum ^ 0xffffffff00000000) >> 32);
					sum = (uint32_t)(full_sum ^ 0x00000000ffffffff);
					data[i] = sum;
				}
				// TODO: Throw an error if carry is not 0
			}

			friend UInt operator+(UInt lhs, const UInt& rhs)
			{
				lhs += rhs;
				return lhs;
			}

		};

		template<size_t bytes>
		struct Rational
		{
			
		};

		template<size_t bytes>
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
