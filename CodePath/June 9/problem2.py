


def can_trust_message(message):
    occurance = [0 for _ in range(26)]
    
    for c in message:
        if c == ' ':
            continue
        if occurance[ord(c) - ord('a')] == 0:
            occurance[ord(c) - ord('a')] = 1
    
    for i in occurance:
        if i == 0:
            return False

    return True
            

if __name__ == "__main__":
    message1 = "sphinx of black quartz judge my vow"
    message2 = "trust me"

    print(can_trust_message(message1)) # True
    print(can_trust_message(message2)) # False