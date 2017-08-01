
class StrVec
{
public:
	StrVec() = default;
	StrVec(const StrVec &);
	StrVec operator=(const StrVec &);
	~StrVec() {free();};
	size_t capacity() const {return cap - elements;}
	size_t size() const {return first_free - elements;}
	std::string *begin() const {return elements;}
	std::string *end() const {return first_free;}
	void push_back(const std::string &); 

private:
	void check_n_allocate() {if(size() == capacity()) reallocate();}
	void reallocate();
	void free();
	std::pair<std::string *, std::string *> allocate_n_copy(const std::string *, const std::string *);

	std::allocator<std::string> strAllocator;
	std::string *elements = nullptr;
	std::string *first_free = nullptr;
	std::string *cap = nullptr;
};
