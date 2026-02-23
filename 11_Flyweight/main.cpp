#include <iostream>
#include <string>
#include <vector>

struct Sentence
{
  struct WordToken
  {
	std::string word;
    bool capitalize;
  };

  explicit Sentence(const std::string& text)
  {
	if (text.empty()) return;

	std::string word = "";
	for (auto& c : text)
	{	
		if (c == ' ')
		{
			if(!word.empty())
				Words.emplace_back(WordToken{word,false});
			word.clear();
		}
		else
		{
			word.push_back(c);
		}
	}
	if (!word.empty())
		Words.emplace_back(WordToken{word,false});
  }

  WordToken& operator[](size_t index)
  {
	Words[index].capitalize = true;
	return *(std::begin(Words) + index);
  }

  std::string str() const
  {
    // todo
	std::string result = "";
	for (auto& c : Words)
	{
		for (auto l : c.word)
		{
			result += c.capitalize ? toupper(l) : l;
		}
		// TODO : only add space if there are more words
		result += ' ';
	}
	return result;
  }
  private:
  	std::string Texto;
	std::vector<WordToken> Words;
};

int main()
{
	Sentence sentence("hello world ");
	sentence[1].capitalize = true;
	std::cout << sentence.str(); // prints "hello WORLD"
	return 0;
}