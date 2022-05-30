#include "producer.h"
#include "substrait/plan.pb.h"
#include <google/protobuf/util/json_util.h>

std::string produce() {
    static const std::string JSON = R"(
{
  "extensionUris": [
    {
      "extensionUriAnchor": 1,
      "uri": "/functions_datetime.yaml"
    },
    {
      "extensionUriAnchor": 2,
      "uri": "/functions_arithmetic_decimal.yaml"
    },
    {
      "extensionUriAnchor": 3,
      "uri": "/functions_aggregate_generic.yaml"
    }
  ],
  "extensions": [
    {
      "extensionFunction": {
        "extensionUriReference": 1,
        "functionAnchor": 1,
        "name": "lte:date_date"
      }
    },
    {
      "extensionFunction": {
        "extensionUriReference": 1,
        "functionAnchor": 2,
        "name": "subtract:date_day"
      }
    },
    {
      "extensionFunction": {
        "extensionUriReference": 2,
        "functionAnchor": 3,
        "name": "multiply:opt_dec_dec"
      }
    },
    {
      "extensionFunction": {
        "extensionUriReference": 2,
        "functionAnchor": 4,
        "name": "subtract:opt_dec_dec"
      }
    },
    {
      "extensionFunction": {
        "extensionUriReference": 2,
        "functionAnchor": 5,
        "name": "add:opt_dec_dec"
      }
    },
    {
      "extensionFunction": {
        "extensionUriReference": 2,
        "functionAnchor": 6,
        "name": "sum:opt_dec"
      }
    },
    {
      "extensionFunction": {
        "extensionUriReference": 2,
        "functionAnchor": 7,
        "name": "avg:opt_dec"
      }
    },
    {
      "extensionFunction": {
        "extensionUriReference": 3,
        "functionAnchor": 8,
        "name": "count:opt"
      }
    }
  ],
  "relations": [
    {
      "root": {
        "input": {
          "sort": {
            "common": {
              "direct": {}
            },
            "input": {
              "aggregate": {
                "common": {
                  "emit": {
                    "outputMapping": [
                      0,
                      1,
                      2,
                      3,
                      4,
                      5,
                      6,
                      7,
                      8,
                      9
                    ]
                  }
                },
                "input": {
                  "project": {
                    "common": {
                      "emit": {
                        "outputMapping": [
                          16,
                          17,
                          18,
                          19,
                          20,
                          21,
                          22
                        ]
                      }
                    },
                    "input": {
                      "filter": {
                        "common": {
                          "direct": {}
                        },
                        "input": {
                          "read": {
                            "common": {
                              "direct": {}
                            },
                            "baseSchema": {
                              "names": [
                                "L_ORDERKEY",
                                "L_PARTKEY",
                                "L_SUPPKEY",
                                "L_LINENUMBER",
                                "L_QUANTITY",
                                "L_EXTENDEDPRICE",
                                "L_DISCOUNT",
                                "L_TAX",
                                "L_RETURNFLAG",
                                "L_LINESTATUS",
                                "L_SHIPDATE",
                                "L_COMMITDATE",
                                "L_RECEIPTDATE",
                                "L_SHIPINSTRUCT",
                                "L_SHIPMODE",
                                "L_COMMENT"
                              ],
                              "struct": {
                                "types": [
                                  {
                                    "i64": {
                                      "nullability": "NULLABILITY_REQUIRED"
                                    }
                                  },
                                  {
                                    "i64": {
                                      "nullability": "NULLABILITY_REQUIRED"
                                    }
                                  },
                                  {
                                    "i64": {
                                      "nullability": "NULLABILITY_REQUIRED"
                                    }
                                  },
                                  {
                                    "i32": {
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "decimal": {
                                      "precision": 19,
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "decimal": {
                                      "precision": 19,
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "decimal": {
                                      "precision": 19,
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "decimal": {
                                      "precision": 19,
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "fixedChar": {
                                      "length": 1,
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "fixedChar": {
                                      "length": 1,
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "date": {
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "date": {
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "date": {
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "fixedChar": {
                                      "length": 25,
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "fixedChar": {
                                      "length": 10,
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  },
                                  {
                                    "varchar": {
                                      "length": 44,
                                      "nullability": "NULLABILITY_NULLABLE"
                                    }
                                  }
                                ],
                                "nullability": "NULLABILITY_REQUIRED"
                              }
                            },
                            "namedTable": {
                              "names": [
                                "LINEITEM"
                              ]
                            }
                          }
                        },
                        "condition": {
                          "scalarFunction": {
                            "functionReference": 1,
                            "args": [
                              {
                                "selection": {
                                  "directReference": {
                                    "structField": {
                                      "field": 10
                                    }
                                  },
                                  "rootReference": {}
                                }
                              },
                              {
                                "scalarFunction": {
                                  "functionReference": 2,
                                  "args": [
                                    {
                                      "literal": {
                                        "date": 10561
                                      }
                                    },
                                    {
                                      "literal": {
                                        "intervalDayToSecond": {
                                          "days": 120
                                        }
                                      }
                                    }
                                  ],
                                  "outputType": {
                                    "date": {
                                      "nullability": "NULLABILITY_REQUIRED"
                                    }
                                  }
                                }
                              }
                            ],
                            "outputType": {
                              "bool": {
                                "nullability": "NULLABILITY_NULLABLE"
                              }
                            }
                          }
                        }
                      }
                    },
                    "expressions": [
                      {
                        "selection": {
                          "directReference": {
                            "structField": {
                              "field": 8
                            }
                          },
                          "rootReference": {}
                        }
                      },
                      {
                        "selection": {
                          "directReference": {
                            "structField": {
                              "field": 9
                            }
                          },
                          "rootReference": {}
                        }
                      },
                      {
                        "selection": {
                          "directReference": {
                            "structField": {
                              "field": 4
                            }
                          },
                          "rootReference": {}
                        }
                      },
                      {
                        "selection": {
                          "directReference": {
                            "structField": {
                              "field": 5
                            }
                          },
                          "rootReference": {}
                        }
                      },
                      {
                        "scalarFunction": {
                          "functionReference": 3,
                          "args": [
                            {
                              "selection": {
                                "directReference": {
                                  "structField": {
                                    "field": 5
                                  }
                                },
                                "rootReference": {}
                              }
                            },
                            {
                              "scalarFunction": {
                                "functionReference": 4,
                                "args": [
                                  {
                                    "cast": {
                                      "type": {
                                        "decimal": {
                                          "precision": 19,
                                          "nullability": "NULLABILITY_NULLABLE"
                                        }
                                      },
                                      "input": {
                                        "literal": {
                                          "i32": 1
                                        }
                                      }
                                    }
                                  },
                                  {
                                    "selection": {
                                      "directReference": {
                                        "structField": {
                                          "field": 6
                                        }
                                      },
                                      "rootReference": {}
                                    }
                                  }
                                ],
                                "outputType": {
                                  "decimal": {
                                    "precision": 19,
                                    "nullability": "NULLABILITY_NULLABLE"
                                  }
                                }
                              }
                            }
                          ],
                          "outputType": {
                            "decimal": {
                              "precision": 19,
                              "nullability": "NULLABILITY_NULLABLE"
                            }
                          }
                        }
                      },
                      {
                        "scalarFunction": {
                          "functionReference": 3,
                          "args": [
                            {
                              "scalarFunction": {
                                "functionReference": 3,
                                "args": [
                                  {
                                    "selection": {
                                      "directReference": {
                                        "structField": {
                                          "field": 5
                                        }
                                      },
                                      "rootReference": {}
                                    }
                                  },
                                  {
                                    "scalarFunction": {
                                      "functionReference": 4,
                                      "args": [
                                        {
                                          "cast": {
                                            "type": {
                                              "decimal": {
                                                "precision": 19,
                                                "nullability": "NULLABILITY_NULLABLE"
                                              }
                                            },
                                            "input": {
                                              "literal": {
                                                "i32": 1
                                              }
                                            }
                                          }
                                        },
                                        {
                                          "selection": {
                                            "directReference": {
                                              "structField": {
                                                "field": 6
                                              }
                                            },
                                            "rootReference": {}
                                          }
                                        }
                                      ],
                                      "outputType": {
                                        "decimal": {
                                          "precision": 19,
                                          "nullability": "NULLABILITY_NULLABLE"
                                        }
                                      }
                                    }
                                  }
                                ],
                                "outputType": {
                                  "decimal": {
                                    "precision": 19,
                                    "nullability": "NULLABILITY_NULLABLE"
                                  }
                                }
                              }
                            },
                            {
                              "scalarFunction": {
                                "functionReference": 5,
                                "args": [
                                  {
                                    "cast": {
                                      "type": {
                                        "decimal": {
                                          "precision": 19,
                                          "nullability": "NULLABILITY_NULLABLE"
                                        }
                                      },
                                      "input": {
                                        "literal": {
                                          "i32": 1
                                        }
                                      }
                                    }
                                  },
                                  {
                                    "selection": {
                                      "directReference": {
                                        "structField": {
                                          "field": 7
                                        }
                                      },
                                      "rootReference": {}
                                    }
                                  }
                                ],
                                "outputType": {
                                  "decimal": {
                                    "precision": 19,
                                    "nullability": "NULLABILITY_NULLABLE"
                                  }
                                }
                              }
                            }
                          ],
                          "outputType": {
                            "decimal": {
                              "precision": 19,
                              "nullability": "NULLABILITY_NULLABLE"
                            }
                          }
                        }
                      },
                      {
                        "selection": {
                          "directReference": {
                            "structField": {
                              "field": 6
                            }
                          },
                          "rootReference": {}
                        }
                      }
                    ]
                  }
                },
                "groupings": [
                  {
                    "groupingExpressions": [
                      {
                        "selection": {
                          "directReference": {
                            "structField": {}
                          },
                          "rootReference": {}
                        }
                      },
                      {
                        "selection": {
                          "directReference": {
                            "structField": {
                              "field": 1
                            }
                          },
                          "rootReference": {}
                        }
                      }
                    ]
                  }
                ],
                "measures": [
                  {
                    "measure": {
                      "functionReference": 6,
                      "args": [
                        {
                          "selection": {
                            "directReference": {
                              "structField": {
                                "field": 2
                              }
                            },
                            "rootReference": {}
                          }
                        }
                      ],
                      "phase": "AGGREGATION_PHASE_INITIAL_TO_RESULT",
                      "outputType": {
                        "decimal": {
                          "precision": 19,
                          "nullability": "NULLABILITY_NULLABLE"
                        }
                      }
                    }
                  },
                  {
                    "measure": {
                      "functionReference": 6,
                      "args": [
                        {
                          "selection": {
                            "directReference": {
                              "structField": {
                                "field": 3
                              }
                            },
                            "rootReference": {}
                          }
                        }
                      ],
                      "phase": "AGGREGATION_PHASE_INITIAL_TO_RESULT",
                      "outputType": {
                        "decimal": {
                          "precision": 19,
                          "nullability": "NULLABILITY_NULLABLE"
                        }
                      }
                    }
                  },
                  {
                    "measure": {
                      "functionReference": 6,
                      "args": [
                        {
                          "selection": {
                            "directReference": {
                              "structField": {
                                "field": 4
                              }
                            },
                            "rootReference": {}
                          }
                        }
                      ],
                      "phase": "AGGREGATION_PHASE_INITIAL_TO_RESULT",
                      "outputType": {
                        "decimal": {
                          "precision": 19,
                          "nullability": "NULLABILITY_NULLABLE"
                        }
                      }
                    }
                  },
                  {
                    "measure": {
                      "functionReference": 6,
                      "args": [
                        {
                          "selection": {
                            "directReference": {
                              "structField": {
                                "field": 5
                              }
                            },
                            "rootReference": {}
                          }
                        }
                      ],
                      "phase": "AGGREGATION_PHASE_INITIAL_TO_RESULT",
                      "outputType": {
                        "decimal": {
                          "precision": 19,
                          "nullability": "NULLABILITY_NULLABLE"
                        }
                      }
                    }
                  },
                  {
                    "measure": {
                      "functionReference": 7,
                      "args": [
                        {
                          "selection": {
                            "directReference": {
                              "structField": {
                                "field": 2
                              }
                            },
                            "rootReference": {}
                          }
                        }
                      ],
                      "phase": "AGGREGATION_PHASE_INITIAL_TO_RESULT",
                      "outputType": {
                        "decimal": {
                          "precision": 19,
                          "nullability": "NULLABILITY_NULLABLE"
                        }
                      }
                    }
                  },
                  {
                    "measure": {
                      "functionReference": 7,
                      "args": [
                        {
                          "selection": {
                            "directReference": {
                              "structField": {
                                "field": 3
                              }
                            },
                            "rootReference": {}
                          }
                        }
                      ],
                      "phase": "AGGREGATION_PHASE_INITIAL_TO_RESULT",
                      "outputType": {
                        "decimal": {
                          "precision": 19,
                          "nullability": "NULLABILITY_NULLABLE"
                        }
                      }
                    }
                  },
                  {
                    "measure": {
                      "functionReference": 7,
                      "args": [
                        {
                          "selection": {
                            "directReference": {
                              "structField": {
                                "field": 6
                              }
                            },
                            "rootReference": {}
                          }
                        }
                      ],
                      "phase": "AGGREGATION_PHASE_INITIAL_TO_RESULT",
                      "outputType": {
                        "decimal": {
                          "precision": 19,
                          "nullability": "NULLABILITY_NULLABLE"
                        }
                      }
                    }
                  },
                  {
                    "measure": {
                      "functionReference": 8,
                      "phase": "AGGREGATION_PHASE_INITIAL_TO_RESULT",
                      "outputType": {
                        "i64": {
                          "nullability": "NULLABILITY_REQUIRED"
                        }
                      }
                    }
                  }
                ]
              }
            },
            "sorts": [
              {
                "expr": {
                  "selection": {
                    "directReference": {
                      "structField": {}
                    },
                    "rootReference": {}
                  }
                },
                "direction": "SORT_DIRECTION_ASC_NULLS_LAST"
              },
              {
                "expr": {
                  "selection": {
                    "directReference": {
                      "structField": {
                        "field": 1
                      }
                    },
                    "rootReference": {}
                  }
                },
                "direction": "SORT_DIRECTION_ASC_NULLS_LAST"
              }
            ]
          }
        },
        "names": [
          "L_RETURNFLAG",
          "L_LINESTATUS",
          "SUM_QTY",
          "SUM_BASE_PRICE",
          "SUM_DISC_PRICE",
          "SUM_CHARGE",
          "AVG_QTY",
          "AVG_PRICE",
          "AVG_DISC",
          "COUNT_ORDER"
        ]
      }
    }
  ]
}
)";
    substrait::Plan plan;
    google::protobuf::util::JsonStringToMessage(JSON, &plan);
    return plan.SerializeAsString();
}
