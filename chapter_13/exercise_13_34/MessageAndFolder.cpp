#include <MessageAndFolder.h>
using std::string;
using std::set;

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMessage(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.removeMessage(this);
}

void Message::add_to_folder()
{
	for(auto f: folders)
		f.addMessage(this);
}

void Message::remove_from_folder()
{
	for(auto f: folders)
		f.removeMessage(this);
}

Message::Message(const Message &m):content(m.content), folders(m.folders)
{
	add_to_folder();
}

Message &Message::operator=(const Message &m)
{
	remove_from_folder;
	content = m.content;
	folders = m.folders;
	add_to_folder();
	return *this;
}

Message::~Message()
{
	remove_from_folder();
}

void Folder::add_to_messages()
{
	for(auto m: messages)
		m->folders.insert(this);
}

void Folder::remove_from_message()
{
	for(auto m:messages)
		m->folders.erase(this);
}

Folder::Folder(const Folder &f): messages(f.messages)
{
	add_to_messages();
}

Folder &Folder::operator=(const Folder &f)
{
	remove_from_message();
	messages = f.message;
	add_to_messages();
	return *this;
}

Folder::~Folder()
{
	remove_from_messages();
}

void swap(Message &a, Message &b)
{
	using std::swap;
	a.remove_from_folder();
	b.remove_from_folder();
	swap(a.content, b.content);
	swap(a.folders. b.folders);
	a.add_to_folder();
	b.add_to_folder();
}

void swap(Folder &a, Folder &b)
{
	using std::swap;
	a.remove_from_message();
	b.remove_from_message();
	swap(a.messages, b.message);
	a.add_to_messages();
	b.add_to_messages();
}












