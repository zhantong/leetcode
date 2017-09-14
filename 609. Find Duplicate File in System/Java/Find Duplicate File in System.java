class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> memory = new HashMap<>();
        for (String path : paths) {
            String[] splits = path.split(" ");
            String base = splits[0];
            for (int i = 1; i < splits.length; i++) {
                String file = splits[i];
                int leftParentIndex = file.indexOf('(');
                String key = file.substring(leftParentIndex + 1);
                if (!memory.containsKey(key)) {
                    memory.put(key, new ArrayList<>());
                }
                memory.get(key).add(base + '/' + file.substring(0, leftParentIndex));
            }
        }
        List<List<String>> result = new ArrayList<>();
        for (List<String> value : memory.values()) {
            if (value.size() > 1) {
                result.add(value);
            }
        }
        return result;
    }
}