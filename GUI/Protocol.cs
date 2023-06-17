using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GUI
{
    internal class Protocol
    {
        public static string signInProtocol(string name, string pw)
        {
            string json = "{\"username\": \"" + name + "\"," +
                            "\"password\": \"" +pw + "\"}";

            return json;
        }

        public static string signUpProtocol(string name, string pw, string email, string street, string apt, string city, string prefix, string number, string year)
        {
            string json = "{\"username\": \"" + name + "\"," +
                            "\"password\": \"" + pw + "\"," +
                            "\"email\": \"" + email + "\"," +
                            "\"street\": \"" + street + "\"," +
                            "\"apt\": \"" + apt + "\"," +
                            "\"city\": \"" + city + "\"," +
                            "\"prefix\": \"" + prefix + "\"," +
                            "\"number\": \"" + number + "\"," +
                            "\"year\": \"" + year + "\"}";

            return json;
        }

        public static string getPlayersProtocol(int roomID)
        {
            string json = "{\"roomID\": " + roomID + "}";

            return json;
        }

        public static string joinRoomProtocol(int roomID)
        {
            string json = "{\"roomID\": " + roomID + "}";

            return json;
        }

        public static string createRoomRequestProtocol(string roomName, int maxUsers, int qCount, int time)
        {
            string json = "{\"roomName\": \"" + roomName +"\"," +
                            "\"maxUsers\": " + maxUsers +"," +
                            "\"questionCount\": " + qCount + "," +
                            "\"answerTimeout\": " + time + "}";

            return json;
        }
        public static string createGetRoomStateProtocol(byte status, bool hasGameBegun, string[] players, byte questionCount, byte answerTimeout)
        {
            string json = "{\"status\": \"" + status + "\", " +
                "\"has game begun\": \"" + hasGameBegun.ToString() +
                "\"players\": \"";
            for (int i = 0; i < players.Length; i++)
            {
                json += players[i] + ", ";
            }
            json += "\"question count\": \"" + questionCount.ToString() + 
                "\"answer time out\": \"" + answerTimeout.ToString() + "}";
            return json;
        }
    }
}
