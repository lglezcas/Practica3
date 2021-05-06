#Tested with Python 3.6.6 and CoAPThon3
from coapthon.client.helperclient import HelperClient

#Change this IP address with the one listed as Interface 0: eth, Link local address LL64
# or the one listed as Interface 1: 6LoWPAN,  Unique local address
#host = "fe80::260:37ff:fe00:fa5d"
hostBR = "fe80::260:37ff:fe00:fa5d"
hostED = "fd01::3ead:411:6422:9e7e:f3c"
port = 5683
path ="led"

while True:
    username = input("Which device do you want to send data? BR (Sprinkler control) or ED (Sensor Hub): ")
    print("You selected: " + username)

    if username == "BR":
        host = hostBR
        print("""Select one command:,
        1: Change or check IP address from Hub Sensor,
        2: Change operation mode""")
        command_selected = input()
        if command_selected == "1":
            path = "ipconfig"
            print("""IP address sensor hub menu:,
            1: Get current IP address,
            2: Change IP address""")
            inst_selected = input()
            if inst_selected == "1":
                client = HelperClient(server=(host, port))
                response = client.get(path)
                print(response.pretty_print())
                client.stop()
            elif inst_selected == "2":
                new_addres = input("Write new address")
                client = HelperClient(server=(host, port))
                response = client.post(path,new_addres)
                print(response.pretty_print())
                client.stop()
            else:
                print("Command not valid... Please try again")
                continue
        elif command_selected == "2":
            path = "opmode"
            op_mode = input("Select operation mode (auto or manual):")
            print("Mode Selected is " + op_mode)
            if op_mode == "auto":
                data_send = "auto"
            elif op_mode == "manual":
                data_send = "manual"
            else:
                data_send = op_mode
                print("Wrong Mode Selected - Try again")
            client = HelperClient(server=(host, port))
            response = client.post(path,data_send)
            print(response.pretty_print())
            client.stop()
    elif username == "ED":
        host = hostED
        print(""""Select one command:,
        1: Change or check sampling rate,
        2: Read temperature,
        3: Read humidity"""")
        command_selected = input()
        if command_selected == "1":
            path = "SRconfig"
            print("""Sample Rate Config menu:,
            1: Get current Sample Rate,
            2: Change sample rate""")
            inst_selected = input()
            if inst_selected == "1":
                client = HelperClient(server=(host, port))
                response = client.get(path)
                print(response.pretty_print())
                client.stop()
            elif inst_selected == "2":
                new_SR = input("Write new sample rate:")
                client = HelperClient(server=(host, port))
                response = client.post(path,new_SR)
                print(response.pretty_print())
                client.stop()
            else:
                print("Command not valid... Please try again")
                continue
        elif command_selected == "2":
            path = "temp"
        elif command_selected == "3":
            path = "humidity"
        else:
            print("Command not valid... Please try again")
            continue
            if op_mode == "auto":
                data_send = "auto"
            elif op_mode == "manual":
                data_send = "manual"
            else:
                data_send = op_mode
                print("Wrong Mode Selected - Try again")
            client = HelperClient(server=(host, port))
            response = client.post(path,data_send)
            print(response.pretty_print())
            client.stop()



       
        print("Couldn't understand you... Please try again")
        continue
    

