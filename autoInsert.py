import json
import requests
import sqlite3


def insert(statement):
    connection = sqlite3.connect(r"C:\Users\97250\Desktop\magshimim\trivia_ofir_tsabban_itay_slavin_2023\Trivia\TriviaDB.sqlite")
    cur = connection.cursor()
    cur.execute(statement)
    connection.commit()
    connection.close()

def main():
    jsonData = requests.get(r"https://opentdb.com/api.php?amount=10&category=32&difficulty=hard&type=multiple").json()[
        "results"]
    connection = sqlite3.connect(
        r"C:\Users\97250\Desktop\magshimim\trivia_ofir_tsabban_itay_slavin_2023\Trivia\TriviaDB.sqlite")
    cur = connection.cursor()
    cur.execute("CREATE TABLE IF NOT EXISTS QUESTIONS(QUESTION TEXT NOT NULL, FIRSTANSWER TEXT NOT NULL, SECONDANSWER TEXT NOT NULL, THIRDANSWER TEXT NOT NULL, FOURTHANSWER TEXT NOT NULL, RIGHTANSWER INT NOT NULL);")
    statement= "INSERT INTO QUESTIONS(QUESTION, FIRSTANSWER ,SECONDANSWER ,THIRDANSWER, FOURTHANSWER, RIGHTANSWER) VALUES"
    for dict in jsonData:
        insert_statemnt = statement + f'{dict["question"] , dict["correct_answer"] , dict["incorrect_answers"][0] , dict["incorrect_answers"][1] , dict["incorrect_answers"][2], 1}'+";"
        print(insert_statemnt)
        insert(insert_statemnt)

    cur.close()

if __name__ == "__main__":
    main()