#!/usr/local/bin/python3.7

# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620 >
# ID : < ee364f21 >
# Date : < 9/25/2019 >
# ######################################################

import os # List of module import statements
import sys # Each one on a line
import re
from pprint import pprint as pp

def readIDs(IDs):
    resultdic = {}
    for ID in IDs:
        resultdic[ID] = {}
    return resultdic

def readinfor(str,index,dic):
    i = 0
    for value in dic.values():
        value[str] = index[i]
        i+=1
    return dic

def readbooks():
    booksdic = {}
    idpattern = r'<book id="(.*?)">'
    authorpattern = r'<author>(.*?)</author>'
    titlepattern = r'<title>(.*?)</title>'
    genrepattern = r'<genre>(.*?)</genre>'
    pricepattern = r'<price>(.*?)</price>'
    datepattern = r'<publish_date>(.*?)</publish_date>'
    descrippattern = r'<description>(.*?)</description>'
    with open('books.xml', 'r') as f:
        books = f.read()
    IDs = re.findall(idpattern,books,re.IGNORECASE)
    booksdic = readIDs(IDs)
    authors = re.findall(authorpattern,books,re.IGNORECASE)
    booksdic = readinfor("author",authors,booksdic)
    titles = re.findall(titlepattern,books,re.IGNORECASE)
    booksdic = readinfor("title",titles,booksdic)
    genres = re.findall(genrepattern, books, re.IGNORECASE)
    booksdic = readinfor("genre", genres, booksdic)
    prices = re.findall(pricepattern, books, re.IGNORECASE)
    booksdic = readinfor("price", prices, booksdic)
    dates = re.findall(datepattern, books, re.IGNORECASE)
    booksdic = readinfor("date", dates, booksdic)
    description = re.findall(descrippattern, books, re.DOTALL)
    booksdic = readinfor("description", description, booksdic)
    return booksdic

def getGenres():
    booksdic = readbooks()
    available_genres = set()
    for infors in booksdic.values():
        available_genres.add(infors["genre"])
    return sorted(list(available_genres))

def getAuthorOf(bookName):
    booksdic = readbooks()
    for infors in booksdic.values():
        if infors["title"] == bookName:
            return infors["author"]
    return None

def getBookInfo(bookID):
    booksdic = readbooks()
    try:
        infors = booksdic[bookID]
    except:
        return None
    return (infors["title"],infors["author"])

def getBooksBy(authorName):
    booksdic = readbooks()
    book_written_by_author = []
    for infors in booksdic.values():
        try:
            if infors["author"] == authorName:
                book_written_by_author.append(infors["title"])
        except:
            pass
    return sorted(book_written_by_author)

def getBooksBelow(bookPrice):
    booksdic = readbooks()
    title_price_less_than_target = []
    for infors in booksdic.values():
        price = float(infors["price"])
        if (price < bookPrice):
            title_price_less_than_target.append(infors["title"])
    return sorted(title_price_less_than_target)

def searchForWord(word):
    booksdic = readbooks()
    pattern = r'\b'+word+r'\b'
    result = []
    for infors in booksdic.values():
        resulttitle = re.search(pattern,infors["title"],re.IGNORECASE)
        resultdes = re.search(pattern,infors["description"],re.IGNORECASE)
        if resulttitle is not None or resultdes is not None:
            result.append(infors["title"])
    return sorted(result)

# # ######################################################
if __name__  == "__main__":
    #q1 = getGenres()
    #print(q1)

    #q2 = getAuthorOf("The Sundered Grail")
    #q2 = getAuthorOf("The Sunderd Grail")
    #print(q2)

    #q3 = getBookInfo("bk105")
    #q3 = getBookInfo("bk10")
    #print(q3)

    #q4 = getBooksBy("Corets, Eva")
    #q4 = getBooksBy("Coret, Eva")
    #pp(q4)

    #q5 = getBooksBelow(1)
    #pp(q5)
    #print(len(q5))

    q6 = searchForWord('e')
    pp(q6)
    print(len(q6))
    pass