namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.

    enum class AccountStatus {
    troll,
    guest,
    user,
    mod
    };

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.

    enum class Action {
    read,
    write,
    remove
    };

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.

    bool display_post(AccountStatus posterStatus, AccountStatus viewerStatus)
    {
        if(posterStatus == AccountStatus::troll)
        {
            return viewerStatus == AccountStatus::troll;
        }
        return true;
    };

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.

    bool permission_check(Action action, AccountStatus accountStatus)
    {
        if(accountStatus == AccountStatus::guest)
        {
            return action == Action::read;
        }
        if(accountStatus == AccountStatus::user || accountStatus == AccountStatus::troll)
        {
            return action == Action::read || action == Action::write;
        }
        if(accountStatus == AccountStatus::mod)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.

    bool valid_player_combination(AccountStatus accountStatusOne, AccountStatus accountStatusTwo)
    {
        if(accountStatusOne == AccountStatus::guest || accountStatusTwo == AccountStatus::guest)
        {
            return false;
        }
        if((accountStatusOne == AccountStatus::troll && accountStatusTwo != AccountStatus::troll) || (accountStatusOne != AccountStatus::troll && accountStatusTwo == AccountStatus::troll))
        {
            return false;
        }
        return true;
    }

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

    bool has_priority(AccountStatus accountStatusOne, AccountStatus accountStatusTwo)
    {
        return accountStatusOne > accountStatusTwo;
    }

}  // namespace hellmath