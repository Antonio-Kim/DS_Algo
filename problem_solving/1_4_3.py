# Part 1
# the answer is : ['c', 'a', 't', 'd', 'o', 'g', 'r', 'b', 'i']
word_list = ['cat', 'dog', 'rabbit']
letter_list = []
for a_word in word_list:
    for a_letter in a_word:
        if a_letter in letter_list:
            continue
        else:
            letter_list.append(a_letter)

print(letter_list)

# Part 2 - Redo the given code using list comprehension
# start1 = time.perf_counter()
print([word[letter] for word in word_list for letter in range(len(word))])

# For an extra challenge, see if you can figure out how to remove the duplicates.
# the answer is: ['c', 'a', 't', 'd', 'o', 'g', 'r', 'a', 'b', 'b', 'i', 't']
print(list(dict.fromkeys([word[letter]
      for word in word_list for letter in range(len(word))])))
