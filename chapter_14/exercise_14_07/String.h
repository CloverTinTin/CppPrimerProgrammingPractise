#include <memory>
#include <utility>

class String
{
friend std::ostream &operator<<(std::ostream &, const String &);
friend std::istream &operator>>(std::istream &, String &);
friend bool operator==(const String &, const String &);
friend bool operator!=(const String &, const String &);
friend String operator+(const String &, const String &);

public:
	String() = default;
	String(const char *);
	String(const String &);
	String(std::initializer_list<char>);
	~String() {free();}
	String &operator=(const String &);
	String &operator=(std::initializer_list<char>);
	char &operator[](const size_t);
	const char &operator[](const size_t) const;
	String &operator+=(const String &);
	size_t size() const {return first_new - elements;}
	size_t capacity() const {return cap - elements;}
	char *begin() const {return elements;}
	char *end() const {return first_new;}
	void push_back(const char);

private:
	void free();
	void checkCapacity() {if(size() == capacity()) reallocate();}
	void reallocate();
	std::pair<char *, char *> copyStr(const char *, const char *);

	std::allocator<char> alloc;
	char *elements = nullptr;
	char *first_new = nullptr;
	char *cap = nullptr;
};
