 StringBuilder sb = new StringBuilder(1000000 * 7);
for (int i = 0; i < 1000000; i++) {
if (e[i]) {
for (int c = 0; c < count[i]; c++) {
sb.append(i).append('\n');
}
}
}