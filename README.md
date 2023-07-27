# AsyncTest
A test for an async node with multiplayer support.

## Version
Unreal Engine 5.2.1

## How to test it?
- Press play in the editor with net mode StandAlone/Client/ListenerServer
- Then press **i** key to change the target bool value to true.

## ListenerActor

- Implements the async node in the blueprint to check when the target actor value changes
![Screenshot 2023-07-27 042822](https://github.com/ingridwarrior2008/AsyncTest/assets/1762283/2352322a-fabf-4ce7-a382-3b2f06e94b64)

## DefaultPawn
- This class will Initialize player input and capture the pressed key to change the target actor variable.
![Screenshot 2023-07-27 043152](https://github.com/ingridwarrior2008/AsyncTest/assets/1762283/10237094-7dbb-4ebf-ae1b-48a9c69a0120)
![Screenshot 2023-07-27 043408](https://github.com/ingridwarrior2008/AsyncTest/assets/1762283/e16da500-72cf-4caf-995c-76075d2b0662)
