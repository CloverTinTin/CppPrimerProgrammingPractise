using std::string;
using std::set;

class Message
{
	friend class Folder;
	friend void swap(Message &, Message &);
public:
	explicit Message(const string &str = ""): content(str) { }
	Message(const Message &);
	Message &operator=(const Message &);
	~Message();
	void save(Folder &);
	void remove(Folder &);

private:
	string content;
	set<Folder *> folders;
	void add_to_folder();
	void remove_from_folder();
};

class Folder
{
	friend class Message;
	friend void swap(Folder &, Folder &);
public:
	Folder() = default;
	Folder(const Folder &);
	Folder &operator=(const Folder &);
	~Folder();
	void addMessage(Message *);
	void removeMessage(Message *);

private:
	set<Message *> messages;
	void add_to_messages();
	void remove_from_messages();
};













