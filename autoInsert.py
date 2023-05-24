import json
import requests
import sqlite3

gay = requests.get(r"https://opentdb.com/api.php?amount=10&category=32&difficulty=hard&type=multiple").json()["results"]
print(json.dumps(gay, indent=4))
con = sqlite3.connect(r"C:\Users\97250\Desktop\magshimim\trivia_ofir_tsabban_itay_slavin_2023\Trivia\TriviaDB.sqlite")
cur = con.cursor()

nigger = "INSERT INTO Questions(QUESTION, FIRSTANSWER ,SECONDANSWER ,THIRDANSWER, FOURTHANSWER, RIGHTANSWER) VALUES "
for x in gay:
    insert_statment  = nigger + f'({x["question"] , x["correct_answer"] , x["incorrect_answers"][0] , x["incorrect_answers"][1] , x["incorrect_answers"][2], 1})'
    cur.execute(insert_statment)

con.commit()