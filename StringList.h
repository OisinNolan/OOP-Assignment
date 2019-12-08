#if ! defined ( STRINGLIST_H )
#define STRINGLIST_H

class StringNode {
    public:
        const char * str;
        StringNode * next;
};

class StringList {
    private:
        StringNode * head;
    public:
        StringList();
        void add(const char * s);
        bool contains(const char * s);
};

#endif