#ifndef TREE_H
#define TREE_H

class Tree {
    public:

        virtual void Seed() { number_seeds_ += 1; };

        int get_number_seeds() { return number_seeds_; }

        bool operator==(Tree &other);

    private:
        static int number_seeds_;
        static int number_trees_;
};

class Coconut: public Tree {
    public:

        void Seed() { Tree::Seed(); Tree::Seed(); };

        int get_number_seeds() { return Tree::get_number_seeds(); }
};

#endif // TREE_H
