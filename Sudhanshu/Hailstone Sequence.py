def hailstone_seq(start):
  list_out = []
  while start > 1:
    list_out.append(int(start))
    if start%2 == 1:
      start = int(start*3+1)
    else:
      start = int(start/2)
  list_out.append(1)
  return list_out
 
if __name__ == "__main__":
  n = input("Enter the number:")
  if n.isnumeric():
    n = int(n)
    list_out = hailstone_seq(n)
    print("Hailstone Sequence: ", list_out)
  else:
    print("Invalid input.")
