
multimap<string, string> families;
for (string lname, cname; cin >> cname >> lname; families.emplace({lname, cname}));

for (const auto &w : families)
  cout << families.second << "  " << families.first << endl;
