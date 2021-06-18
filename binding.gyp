{
  "targets": [
    {
      "target_name": "native",
      "include_dirs" : [
            "addons",
            "<!(node -e \"require('nan')\")"
        ],
        "sources": [
            "addons/FibonacciNumbers/FibonacciNumbers.cpp",
            
        ]
    }
  ]
}