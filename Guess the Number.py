import random

def get_user_input(prompt, data_type=str):
    while True:
        try:
            user_input = data_type(input(prompt))
            return user_input
        except ValueError:
            print("Invalid input. Please try again.")

def generate_random_number(min_value, max_value):
    return random.randint(min_value, max_value)

def play_guess_the_number():
    print("Welcome to Guess the Number game!")
    print("I will choose a random number, and you have to guess it.")

    min_value = get_user_input("Enter the minimum value: ", int)
    max_value = get_user_input("Enter the maximum value: ", int)
    secret_number = generate_random_number(min_value, max_value)

    attempts = 0
    while True:
        guess = get_user_input("Guess the number: ", int)
        attempts += 1

        if guess == secret_number:
            print(f"Congratulations! You guessed the number {secret_number} in {attempts} attempts.")
            break
        elif guess < secret_number:
            print("Try again. The secret number is higher.")
        else:
            print("Try again. The secret number is lower.")

if __name__ == "__main__":
    play_guess_the_number()
