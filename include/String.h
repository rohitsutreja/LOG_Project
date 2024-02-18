#include <cstring>
#include <iostream>
#include <memory>
#include "..\include\Exception.h" 

#ifndef STRING
#define STRING

namespace Util
{

	class String
	{

	private:
		std::unique_ptr<char[]> m_Buffer;
		size_t m_size;

	public:

		static String toString(int num);
	    static String toString(const String& s) { return s; }

		String(const char* str = "");
		String(const String& other);
		String(String&& other) noexcept;

		bool empty() const;
		size_t length() const;
		size_t indexOf(char character) const;
		String substring(size_t index = 0, size_t size = -1) const;
		String reverse() const;
		String& append(const String& other);
		String& toUpperCase() noexcept;
		String& toLowerCase() noexcept;
		
		const char* getCStyleString() const;
		String& operator=(const String& other);
		String& operator=(String&& other) noexcept;
		char& operator[](size_t index) const;


		friend String operator+(const String& str1, const String& str2);
		friend bool operator==(const String& str1, const String& str2) noexcept;
		friend bool operator!=(const String& str1, const String& str2) noexcept;
		friend std::ostream& operator<<(std::ostream& stream, const String& string);

		~String() = default;
	};

	String operator+(const String& str1, const String& str2);
	bool operator==(const String& str1, const String& str2) noexcept;
	bool operator!=(const String& str1, const String& str2) noexcept;
	std::ostream& operator<<(std::ostream& stream, const String& string);

}

#endif