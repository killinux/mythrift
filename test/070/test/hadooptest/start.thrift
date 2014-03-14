namespace java Test

struct UserProfile {
1: i32 uid,
       2: string name,
       3: string blurb,
       4: i32 month,
       5: i32 day,
       6: i32 year
}
service UserStorage {
    void repeat(1: UserProfile user)
        void daysold(1: UserProfile user)
}
