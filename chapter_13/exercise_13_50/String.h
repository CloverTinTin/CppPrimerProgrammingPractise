#include <memory>
#include <utility>

class String
{
public:
	String() = default;
	String(const char *);
	String(const String &);
	String(String &&) noexcept;
	~String() {free();}
	String &operator=(const String &);
	String &operator=(String &&) noexcept;
	size_t size() const {return first_new - elements;}
	size_t capacity() const {return cap - elements;}
	char *begin() const {return elements;}
	char *end() const {return first_new;}
	void push_back(char);

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
