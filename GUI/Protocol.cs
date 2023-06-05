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
            string json = "{{\"username\": " + name + "}," +
                            "{\"password\": " +pw + "}}";

            return json;
        }
    }
}
