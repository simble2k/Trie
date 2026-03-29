class NaiveDictionary:
    def __init__(self):
        self.dict = []

    def insert(self, word: str):
        self.dict.append(word)

    def search(self, word: str) -> bool:
        return word in self.dict