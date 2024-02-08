// Baekjoon
// 14725 개미굴

#include <iostream>
#include <map>		//for sort alphabet
#include <vector>

int	n, k[1000];

class trieNode
{
private:
	std::map<std::string, trieNode*>	ch;

public:
	void	insert(std::vector<std::string> &line, int level) {
		if (level == line.size())	return ;
		if (ch.find(line[level]) == ch.end())	// fail find
			ch[line[level]] = new trieNode();
		ch[line[level]]->insert(line, level + 1);
	}

	void	print_tree(int	level) {
		for (auto &c : ch) {
			for (int i=0;i<level;++i)
				std::cout << "--";
			std::cout << c.first << '\n';
			c.second->print_tree(level + 1);
		}
	}

};


int	main()
{
	// input
	std::cin >> n;
	trieNode	*root = new trieNode();
	for (int i=0;i<n;++i) {
		std::cin >> k[i];
		std::vector<std::string>	line(k[i]);
		for (int j=0;j<k[i];++j) {
			std::cin >> line[j];
		}
		root->insert(line, 0);
	}
	root->print_tree(0);

	return (0);
}