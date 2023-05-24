import json

import requests
import sqlite3

json = requests.get(r"https://opentdb.com/api.php?amount=10&category=19&type=multiple").json()["results"]

con = sqlite3.connect("path")
cur = con.cursor()

insert_statment = "INSERT INTO "
for( in gay)
cur.execute("")