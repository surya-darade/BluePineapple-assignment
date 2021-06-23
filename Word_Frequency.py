def main():
    s = input('Enter a sentence: ')
    d = {}
    for k in s.split():
        if k not in d:
            d[k] = 1
        else:
            d[k]+=1
    for word,count in d.items():
        print(f"'{word}' occurs {count} times in the given sentence.")

if __name__=='__main__':
    main()