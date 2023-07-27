# AsyncTest
A test for an async node with multiplayer support.

## Version
Unreal Engine 5.2.1

## How to test it?
- Press play in the editor with net mode StandAlone/Client/ListenerServer
- Then press **i** key to change the target bool value to true.

## ListenerActor

- Implements the async node in the blueprint to check when the target actor value changes
![Screenshot 2023-07-27 051031](https://github.com/ingridwarrior2008/AsyncTest/assets/1762283/1dbdef3f-92ec-47f7-b916-9a9d3d35969b)

## DefaultPawn
- This class will Initialize player input and capture the pressed key to change the target actor variable.
![Screenshot 2023-07-27 043152](https://github.com/ingridwarrior2008/AsyncTest/assets/1762283/64a4d206-6827-473f-9f05-03b03fbf1c1d)

![Screenshot 2023-07-27 043408](https://github.com/ingridwarrior2008/AsyncTest/assets/1762283/61449baf-4005-4c4c-9dc0-dfe5ade19043)
